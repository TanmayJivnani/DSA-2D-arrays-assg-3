#include<iostream>
using namespace std;
// By Tanmay Jivnani
int main()
{   
    int m=3; int n=4;
    int arr[m][n]={{0,1,2,0},{3,4,5,2}, {1,3,1,5}};
    for(int i=0; i<m; i++){
        for(int j=0; j<n;j++){
            cout << arr[i][j]<< " ";
        }
        cout << endl;
    }
    //3rd Method - Most Optimized

        
        bool zeroInRow=false;  //false -> no 0 in 0th row 
        bool zeroInCol=false;  //false -> no 0 in 0th col


        // check for existing 0 in 0th row & col (used to store data of 0s)
        for(int j=0; j<n; j++){
            if(arr[0][j]==0) {
                zeroInRow=true; //zero exists
                break; // no need to check further
            }
        }
        for(int i=0; i<m; i++){
            if(arr[i][0]==0) {
                zeroInCol=true; //zero exists
                break; 
            }
        }
        // traverse array excluding 0th Row & Col
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(arr[i][j]==0){
                    arr[i][0]=0; //using 0th col to store data about 0's
                    arr[0][j]=0; //using 0th row to store data about 0's
                }
            }
        }

        // tranform req. row's and col's to 0s
        // col transformation
        for(int j=1; j<n; j++){  //j=1 start
            if(arr[0][j]==0){
                for(int i=0; i<m; i++){
                    arr[i][j]=0;
                }
            }
        }
        //row transformation
        for(int i=1; i<m; i++){
            if(arr[i][0]==0){
                for(int j=0; j<n; j++){
                    arr[i][j]=0;
                }
            }
        }

        // convert 0th Row and Col if req.
        if(zeroInRow){
            for(int j=0; j<n; j++){
                arr[0][j]=0;    //row convert
            }
        }
        if(zeroInCol){
            for(int i=0; i<m; i++){
                arr[i][0]=0;  //col convert
            }
        }

    //final printing
    cout << "\nAfter Transformation: "<< endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n;j++){
            cout << arr[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}



    
        
        
