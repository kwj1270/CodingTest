#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int arr[100001][3];
    int minArr[2][3];
    int maxArr[2][3];
    
    for(int i=0; i < n; i++){
        for(int j=0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int j=0; j < 3; j++){
        minArr[0][j] = maxArr[0][j] = arr[0][j];
    }
    
    for(int i=1; i < n; i++){
        maxArr[1][0] = max(maxArr[0][0], maxArr[0][1])+arr[i][0];
        maxArr[1][1] = max(maxArr[0][1], max(maxArr[0][0], maxArr[0][2]))+arr[i][1];
        maxArr[1][2] = max(maxArr[0][2], maxArr[0][1])+arr[i][2];
        
        minArr[1][0] = min(minArr[0][0], minArr[0][1])+arr[i][0];
        minArr[1][1] = min(minArr[0][1], min(minArr[0][0], minArr[0][2]))+arr[i][1];
        minArr[1][2] = min(minArr[0][2], minArr[0][1])+arr[i][2];
        
        maxArr[0][0] = maxArr[1][0];
        maxArr[0][1] = maxArr[1][1];
        maxArr[0][2] = maxArr[1][2];

        minArr[0][0] = minArr[1][0];
        minArr[0][1] = minArr[1][1];
        minArr[0][2] = minArr[1][2];
    }
    
    int maxValue = max(maxArr[0][0],max( maxArr[0][1],maxArr[0][2]));
    int minValue = min(minArr[0][0],min( minArr[0][1],minArr[0][2]));
    cout << maxValue << " " << minValue << "\n";

}
