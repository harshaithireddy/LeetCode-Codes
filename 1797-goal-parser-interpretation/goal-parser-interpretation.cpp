class Solution {
public:
    string interpret(string command) {
        string j="";
        int i;
        for(i=0;i<command.size();i++){
           if(command[i]=='G'){
               j += 'G';
           }
           else if(command[i] == '('){
               if(command[i+1] == ')'){
                   j += 'o';
               }
               else{
                j += 'a';
                j += 'l';
               }
           }  
       }
       return j;
    }
};