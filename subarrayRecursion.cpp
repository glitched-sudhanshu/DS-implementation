#include <iostream>

using namespace std;

void subarray(int arr[],int s,int e){
    if(e==3){
        return;
    }
    if(s>e){
        subarray(arr,0,e+1);
    }
    else{
      for(int j=s;j<e;j++){
        cout<<arr[j];
      }
      cout<<arr[e]<<endl;
      subarray(arr,s+1,e);
    }
    
}

int main()
{
    int arr[] = {1,2,3};
    subarray(arr,0,0);
    return 0;
}