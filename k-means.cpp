/*k-means,仅二维数组.还可优化.
*@Author:guotao.gt@alibaba-inc.com
*@Create:2017-05-17
*/
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define THRESHOLD 0.5

//定义簇个数
int k;

//定义实例的结构体
struct Instance {
  float x;
  float y;
};

//计算两个实例间的欧式距离
float getDistance(Instance ins1, Instance ins2) {
  // return sqrt((ins1.x - ins2.x) * (ins1.x - ins2.x) + (ins1.y - ins2.y) *(ins1.y - ins2.y));
  // return sqrt(pow((ins1.x - ins2.x),2) + pow((ins1.y - ins2.y),2));
  return hypot(ins1.x - ins2.x, ins1.y - ins2.y);  //更简洁的函数 c++11
}

//根据质心，决定当前实例属于哪个簇
int getClusterOfInstance(vector<Instance> means, Instance Instance) {
  float dist = getDistance(means[0], Instance);  //用第一个实例初始化
  float tmp;
  int label = 0;  //标示当前实例属于哪个簇
  for (int i = 1; i < k; i++) {
    tmp = getDistance(means[i], Instance);
    if (tmp < dist) {
      dist = tmp;
      label = i;
    }
  }
  return label;
}

//计算准则函数值,给定簇集的组内平方和（WCSS within-cluster sum of squares）
float computeWcssOfClusters(vector<vector<Instance> > clusters, vector<Instance> means) {
  float sumOfSquares = 0;
  for (int i = 0; i < k; i++) {
    // vector<Instance> t = clusters[i];
    for (int j = 0; j < clusters[i].size(); j++) {
      sumOfSquares += getDistance(clusters[i][j], means[i]);
    }
  }
  // cout<<"sumOfSquares:"<<sumOfSquares<<endl;
  return sumOfSquares;
}

//获得当前簇的均值/质心
Instance getMeanOfCluster(vector<Instance> cluster) {
  int num = cluster.size();
  Instance instance;
  double sumX = 0, sumY = 0;
  for (int i = 0; i < num; i++) {
    sumX += cluster[i].x;
    sumY += cluster[i].y;
  }
  instance.x = sumX / num;
  instance.y = sumY / num;
  return instance;
}

//根据质心将实例分配到簇
vector<vector<Instance> > assignInstanceToClusters(vector<Instance> instances,vector<Instance> means) {
  vector<vector<Instance> > clusters(k);
  for (int i = 0; i < instances.size(); i++) {
    int lable = getClusterOfInstance(means, instances[i]);
    clusters[lable].push_back(instances[i]);
  }
  return clusters;
}

//初始化质心. 这里只用一种简单的方式,将前k个实例的值作为k个簇的质心
//可以优化:用随机方法初始化质心;用Canopy进行粗聚类得到k值
vector<Instance> initialMeans(vector<Instance> instances) {
  vector<Instance> means;
  Instance instance;
  for (int i = 0; i < k; i++) {
    instance.x = instances[i].x;
    instance.y = instances[i].y;
    means.push_back(instance);
    // cout<<"means["<<i<<"]:"<<means[i].x<<"  "<<means[i].y<<endl;
  }
  return means;
}

//打印簇
void printClusters(vector<vector<Instance> > clusters,vector<Instance> means) {
  for (int lable = 0; lable < k; lable++) {
    cout << "第" << lable + 1 << "个簇,质心(" <<means[lable].x<<","<<means[lable].y<<"),实例:"<<endl;
    for (int i = 0; i < clusters[lable].size(); i++) {
      cout << "(" << clusters[lable][i].x << "," << clusters[lable][i].y<< ")\t";
    }
    cout << endl;
  }
}

//模型入口
void kMeansModel(vector<Instance> instances) {
  vector<Instance> means = initialMeans(instances);
  vector<vector<Instance> > clusters = assignInstanceToClusters(instances,means);
  float oldWcss = -1;
  float newWcss = computeWcssOfClusters(clusters, means);
  while (fabs(newWcss - oldWcss) >=THRESHOLD) {  //当新旧值相差小于阈值时迭代终止
    for (int i = 0; i < k; i++) {  //更新每个簇的中心点
      means[i] = getMeanOfCluster(clusters[i]);
    }
    oldWcss = newWcss;
    for (int i = 0; i < k; i++) {
      clusters[i].clear(); //清空每个簇
    }
    newWcss = computeWcssOfClusters(clusters, means);
    clusters = assignInstanceToClusters(instances,means);
  }
  printClusters(clusters,means);
}

int main() {
  char fname[512];
  cout << "请输入存放数据的文件名： ";
  cin >> fname;
  cout << "请输入期望的簇的个数：";
  cin>>k;
  ifstream infile;
  infile.open(fname, ios::in);
  if (!infile) {
    cout << "文件无法打开" << fname << endl;
    return -1;
  }
  int count = 0;
  vector<Instance> instances;
  Instance Instance;
  //从文件流中读入数据
  while (!infile.eof()) {
    count++;
    if (count % 2 == 1)
      infile >> Instance.x;
    else {
      infile >> Instance.y;
      instances.push_back(Instance);
    }
  }
  kMeansModel(instances);
  return 0;
}
