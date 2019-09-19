#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;


vector<long double>  PointsX, PointsY, Points_Pad_x, Points_Pad_y;
vector<int> Indices_Pad;


ifstream MeshFileX, MeshFileY;
long double X, Y;


int main(){

  MeshFileX.open("COORD_ZONE_X.txt");
  MeshFileY.open("COORD_ZONE_Y.txt");
  if ((!MeshFileX)||(!MeshFileY)){

    cout << "Pas de fichier à lire !" ;
    return 0;

  }
else
  {
    while (MeshFileX >> X)
    {
PointsX.push_back(X);

}
//cout << PointsX[126] << endl;
MeshFileX.close();

    while (MeshFileY >> Y)
    {
  PointsY.push_back(Y);
}
//cout << Points_Pad_y.size();

  MeshFileY.close();


}
//cout << PointsX[0] << endl;
//cout << PointsY[0] << endl;

for (int i=0;i<PointsX.size();i++)
{

  //cout << "Boucle 3" << endl;
if  ((1.1E-3 >= sqrt(pow(PointsX[i]-1E-3,2)+pow(PointsY[i],2))) && (0.9E-3 <= sqrt(pow(PointsX[i]-1E-3,2)+pow(PointsY[i],2))))
{

//Points_Pad_x.push_back(PointsX[i]);
//Points_Pad_y.push_back(PointsY[i]);
Indices_Pad.push_back(i);

if (((M_PI+30*M_PI/180)/2 < atan2(PointsY[i], PointsX[i]-0.001))|| ((M_PI-30*M_PI/180)/2 > atan2(PointsY[i], PointsX[i]-0.001)))
{

  Indices_Pad.pop_back();
}
else{}
}

else{}

//if (7.5E-4 > PointsX[i] || 1.25E-3 < PointsX[i]) //(15/2 <= 180*atan2(PointsY[i], PointsX[i]-0.001)/M_PI)//|| ((M_PI-15*M_PI/180)/2 > atan2(PointsY[i], PointsX[i]-0.001)))
//{
//Points_Pad_x.pop_back();
//Points_Pad_y.pop_back();
//Indices_Pad[i] = 9999999;
//}
//else {}


}
for (int k=0;k < Indices_Pad.size(); k++)
{


//cout << Indices_Pad.size() << endl;
//cout << Indices_Pad[k] << endl;
}
cout << Indices_Pad.size();
//cout << 180*atan2(PointsY[0], PointsX[0]-0.001)/M_PI << endl;
return 0;

}
