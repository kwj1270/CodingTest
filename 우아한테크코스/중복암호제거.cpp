#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string cryptogram = "browoanoommnaon";
    //string cryptogram = "zyelleyz";
    stack<char> answer_bucket;
    string answer = "";
    for(int i=0; i < cryptogram.size(); i++){
        if(answer_bucket.empty()) { answer_bucket.push(cryptogram[i]); continue;}
        if(!answer_bucket.empty() && answer_bucket.top() == cryptogram[i]) { answer_bucket.pop(); continue;}
        answer_bucket.push(cryptogram[i]);
    }
    while (!answer_bucket.empty()) {
        answer += answer_bucket.top(); answer_bucket.pop();
    }
    reverse(answer.begin(), answer.end());
    cout << answer << "\n";
    
    
    return 0;
}


