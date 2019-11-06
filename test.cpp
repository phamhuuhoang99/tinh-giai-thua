#include<iostream>
#include<vector>
using namespace std;
bool isMonotonous(vector<int> se) {
    if(se.size()==1) return true;
    if(se[0]>se[1]){
        for(int i=1;i<se.size()-1;i++){
                if(se[i]<=se[i+1]) return false;
            }
    }
    if(se[0]<se[1]){
        for(int i=1;i<se.size();i++){
            if(se[i]>=se[i+1]) return false;
        }   
    }
    if(se[0]==se[1]) return false;
    return true;
}
int main(){
	vector<int> vec;
	vec.push_back(6);
	vec.push_back(7);
	
	vec.push_back(8);
	if(isMonotonous(vec)){
		cout<<"aye";
	}
}	
