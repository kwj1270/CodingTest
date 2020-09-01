참고 : https://www.youtube.com/watch?v=yWWbLrV4PZ8  

![1](https://user-images.githubusercontent.com/50267433/91639573-97031180-ea52-11ea-9055-37ba6015b0ac.jpg)      
**J**는 접두사 및 **접두사와 접미사가 일치하는 연속된 값**을 의미한다.        
**I**는 접미사를 의미한다.      
   
![2](https://user-images.githubusercontent.com/50267433/91639592-b601a380-ea52-11ea-9aee-72ab7dc56ffc.jpg)  
그렇기 때문에 접두사랑 접미사가 같으면 j의 값을 넣어준다.            
앞서 말했듯 j는 접두사와 접미사가 일치하는 연속된 값을 의미하고 여기서 j는 0부터 시작했으므로 +1 해준 값을 넣어준다.             
  
![3](https://user-images.githubusercontent.com/50267433/91639636-f06b4080-ea52-11ea-8eaf-267bb1ca0442.jpg)         
![4](https://user-images.githubusercontent.com/50267433/91639694-52c44100-ea53-11ea-9174-8827b8ab227b.jpg)  
   
그리고 위에서 +1 처리를 해준것은 개수가 1부터 시작하는 것을 맞춰주기 위한 것도 있지만         
연속된 값을 나타내야 하므로(다음으로 넘어가야하므로) +1을 해주는 것이기도 하다.         
그리고 계속 계산한다.      
       
![5](https://user-images.githubusercontent.com/50267433/91639687-4809ac00-ea53-11ea-9905-d040fc865d65.jpg)    
J가 가리키는 값이랑 I가 가리키는 값이 다를때는 **while**문으로 처리를 해주고 있다.          
이는 사진에서 설명한 것과 같이 값이 연속되지 않는 경우 0으로 돌아간다.            
그렇다면 연속된 경우는 어떤것인지 알기위해서 아래와 같은 문자를 사용했다.           
     
 ### 위와 다른 문자열 사용이므로 주의!
 
![15](https://user-images.githubusercontent.com/50267433/91639737-a20a7180-ea53-11ea-94cf-4211c0bc4ea6.jpg)      
![16](https://user-images.githubusercontent.com/50267433/91639780-e0079580-ea53-11ea-947f-95e6efc909af.jpg)      
      
위 그림과 같이 aba는 맞았지만 c와 b가 다르기 때문에 ```j=[j-1] -> table[3-1] -> j = 1이 된것이다.```      
   
![17](https://user-images.githubusercontent.com/50267433/91639789-f0b80b80-ea53-11ea-9036-2afb1bb85e50.jpg)    
![18](https://user-images.githubusercontent.com/50267433/91639794-f7468300-ea53-11ea-88ac-abe17d509d18.jpg)   
이후 똑같이 진행해주면 된다.     
앞서 말햇듯이 j는 **접두사와 접미사가 일치하는 값 자체**이기 때문에 b가 있는 인덱스는 j++을 해준값 2가 들어온다.     
그리고 ```table[]```을 사용한 이유는 **중복처리**를 해주기 위해서이기도 하다.   
  
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
