참고 : https://www.youtube.com/watch?v=yWWbLrV4PZ8

```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;


// abacaababa
// a 랑 b랑 다른데 j는 증가안함
// a 랑 a랑 같으므로 ++j됨
// table[2] = 1;
// j == 1 -> b i== 3 -> c 다르므로
// j = table[0]의 값을 가짐 j = 0;
// j == 0 i == 4 a == a 같으므로
// j=1 이되고 table[4] == 1;
// j == 1 i == 5 -> b 랑 a 다르므로
// j == table[0] -> 0
// j = 0, i == 6 -> aa 같으므로
// j=1 table[i] =1;
// j=1 i == 7 b==b 같으므로
// table[7] = 2; j == 2
// j=2 i == 8 a a 같으므로
// table[8] = 3;
// j= 3 -> c // i=9 == b 다르므로
// j = table[3-1] -> j = 1;
// patter[1] == pattern[9] 랑 같으면
// 같다. ++J 를 해주기때문에 2가 된다.

vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    
    int j = 0;
    for(int i=1; i < table.size(); i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

int main(){
    string pattern = "abacaababa";
    vector<int> table = makeTable(pattern);
    for(int i=0; i < table.size(); i++){
        cout << table[i] << " ";
    }
    
    return 0;
}

```

```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;


// abacaababa
// a 랑 b랑 다른데 j는 증가안함
// a 랑 a랑 같으므로 ++j됨
// table[2] = 1;
// j == 1 -> b i== 3 -> c 다르므로
// j = table[0]의 값을 가짐 j = 0;
// j == 0 i == 4 a == a 같으므로
// j=1 이되고 table[4] == 1;
// j == 1 i == 5 -> b 랑 a 다르므로
// j == table[0] -> 0
// j = 0, i == 6 -> aa 같으므로
// j=1 table[i] =1;
// j=1 i == 7 b==b 같으므로
// table[7] = 2; j == 2
// j=2 i == 8 a a 같으므로
// table[8] = 3;
// j= 3 -> c // i=9 == b 다르므로
// j = table[3-1] -> j = 1;
// patter[1] == pattern[9] 랑 같으면
// 같다. ++J 를 해주기때문에 2가 된다.

vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    
    int j = 0;
    for(int i=1; i < table.size(); i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parrentSize = parent.size();
    int patternSize = pattern.size();
    
    int j = 0;
    for(int i=0; i < parent.size();i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternSize-1){
                cout << i-patternSize+1 << " ";
                j = table[j];
            } else {
                j++;
            }
        }
    }
}


int main(){
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    KMP(parent, pattern);
    
    return 0;
}

```
