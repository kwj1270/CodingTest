#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m; // id랑 닉네임, 명령어 저장 용도
    vector<string> nicknames;
    
    for(int i=0; i < record.size(); i++){
        stringstream ss;
        string command;
        string id;
        string nickname;

        ss.str(record[i]);
        ss >> command;
        if(command == "Change"){
            ss >> id;
            ss >> nickname;
            m[id] = nickname;
            continue;
        }
        else if(command == "Leave"){
            ss >> id;
            nicknames.push_back(id);
            answer.push_back("님이 나갔습니다.");
            continue;
        }
        else if(command == "Enter"){
            ss >> id;
            ss >> nickname;
            m[id] = nickname;
            nicknames.push_back(id);
            answer.push_back("님이 들어왔습니다.");
            continue;
        }
    }
    for(int i=0; i < answer.size(); i++){
        answer[i] = m[nicknames[i]] + answer[i];
    }
    return answer;
}
