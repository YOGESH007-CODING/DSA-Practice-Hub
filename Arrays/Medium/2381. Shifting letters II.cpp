#include <iostream>
#include <vector>

//Final Solution After learning about Difference Array 
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shift(s.size(),0);
        for(int i = 0;i<shifts.size();i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];
            if(dir==1){
                shift[start]++;
                if(end+1<s.size()){
                    shift[end+1]--;
                }
            }
            else{
                shift[start]--;
                if(end+1<s.size()){
                    shift[end+1]++;
                }
            }
        }
        int imp = 0;
        for(int i = 0;i<s.size();i++){
            imp += shift[i];
            if((s[i]+((imp%26+26)%26))>122){
                s[i]= s[i]-26 +((imp%26+26)%26);
            }else{
                s[i] = s[i]+((imp%26+26)%26);
            }
        }
        return s;
    }
};

//Brute Force
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shift(s.size(),0);
        for(int i = 0;i<shifts.size();i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];
            if(dir==1){
                for(int i = start;i<=end;i++){
                    shift[i]++;
                }
            }
            else{
                for(int i  = start;i<=end;i++){
                    shift[i]--;
                }
            }
        }
        for(int i = 0;i<s.size();i++){
            if((s[i]+((shift[i]%26+26)%26))>122){
                s[i]= s[i]-26 +((shift[i]%26+26)%26);
            }else{
                s[i] = s[i]+((shift[i]%26+26)%26);
            }
            // cout<<((shift[i]%26+26)%26)<<endl;
        }
        return s;
    }
};