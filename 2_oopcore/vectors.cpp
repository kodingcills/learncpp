#include <iostream>
#include <vector>
using namespace std;

double averageScore(const vector<double> & scores){
    if (scores.empty()){
        return 0;
    }
    double avg = 0.0;
    for(double v:scores)   {
        avg+=v;
    }
    return avg/(int)scores.size();
}

void removeBelow(vector<double>& scores, double threshold){
    for(int i = 0; i < (int)scores.size();){
        if(scores.at(i) < threshold){
            scores.erase(scores.begin()+i);
        }else{
            i++;
        }
    }
}

int main() {
    // Your code goes here
    vector<double> scores =    {95.0, 62.0, 78.0, 45.0, 88.0, 55.0, 91.0};
    cout << averageScore(scores) << endl;
    removeBelow(scores, 70.0);
    for(double v:scores){
        cout << v << " ";
    }
    cout << endl;

    cout << averageScore(scores) << endl;
    vector<double> aboveNinety;
for(double v : scores){
    if(v > 90.0)
        aboveNinety.push_back(v);
}
for(double v : aboveNinety){
    cout << v << " ";
}
cout << endl;
    cout << endl;
    return 0;
}