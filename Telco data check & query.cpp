#include<bits/stdc++.h>
using namespace std;

vector<string> split(string s, char delimiter){
    vector<string> result;
    string token;
    stringstream ss(s);
    while(getline(ss, token, delimiter)){
        if(!token.empty()){
            result.push_back(token);
        }
    }
    return result;
}

bool checkPhoneNumb(string s){
    int size_ = s.size();
    if(size_ != 10) return false;
    for(int i = 0; i < size_; ++i){
        if(!isdigit(s[i])) return false;
    }
    return true;
}

bool checkDate(string s){
    vector<string> tmp = split(s, '-');
    int year = stoi(tmp[0]), month = stoi(tmp[1]), day = stoi(tmp[2]);
    if(year <= 0 || month < 0 || month > 12 || day < 0 || day > 31) return false;
    return true;
}

bool checkTime(string s){
    vector<string> tmp = split(s, ':');
    int hour = stoi(tmp[0]), minutes = stoi(tmp[1]), second = stoi(tmp[2]);
    if(hour < 0 || hour > 24 || minutes < 0 || minutes > 60 || second < 0 || second > 60) return false;
    return true;
}

int toSecond(string s){
    int result = 0;
    vector<string> tmp = split(s, ':');
    return 3600*stoi(tmp[0]) + 60*stoi(tmp[1]) + stoi(tmp[2]);
}

int durationCall(string s1, string s2){
    return toSecond(s2) - toSecond(s1);
}

int main(){
    string s;
    int checkPhoneNumber = 1, totalCall = 0;
    unordered_map<string, int> numberCallFrom;
    unordered_map<string, int> countTimeCallFrom;
    while(getline(cin, s) && s != "#"){
        vector<string> tmp = split(s, ' ');
        string phoneNum1 = tmp[1], phoneNum2 = tmp[2], date = tmp[3], time1 = tmp[4], time2 = tmp[5];
        if(checkPhoneNumb(phoneNum1) && checkPhoneNumb(phoneNum2)){
             if(checkDate(date) && checkTime(time1) && checkTime(time2)){
                 ++numberCallFrom[phoneNum1];
                 ++totalCall;
                 countTimeCallFrom[phoneNum1] += durationCall(time1, time2);
             }
        }else{
            checkPhoneNumber = 0;
        }
    }

    while(getline(cin, s) && s != "#"){
        vector<string> tmp = split(s, ' ');
        string cmd = tmp[0];
        if(cmd == "?check_phone_number"){
            cout << checkPhoneNumber << '\n';
        }else if(cmd == "?number_calls_from"){
            cout << numberCallFrom[tmp[1]] << '\n';
        }else if(cmd == "?number_total_calls"){
            cout << totalCall << '\n';
        }else if(cmd == "?count_time_calls_from"){
            cout << countTimeCallFrom[tmp[1]] << '\n';
        }
    }
}
