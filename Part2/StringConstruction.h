#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <string>
using std::string;
#include <iostream>
using std::cout;


// TODO: your code goes here:

#include <vector>
using std::vector;

vector<char> existChar;
vector<string> subStrings;

bool newChar(int pos, string & input){
    for(auto n : existChar){
        if (input[pos] == n){
            return false;
        }
    }
    return true;
}
int repeat(int len){

}

int stringConstruction(string input, int appendCost, int cloneCost){
    int pos = 0;    

    int cost = 0;
    string out = "";
    out.push_back(input[0]);
    existChar.push_back(input[0]);
    cost += appendCost;
    if(input[1] == input[0]){
        if (appendCost < cloneCost){
            cost+= appendCost;
        }
        else{
            cost+= cloneCost;
        }
        out.push_back(input[1]);
    }
    else{
        cost+= appendCost;
        out.push_back(input[1]);
        existChar.push_back(input[1]);
    }
    pos = 2;
    
    string temp= "";

    string copy = input.substr(pos, input.size()-1);
    while(out != input){
        cout << "woeowowowo\n";
        bool checking = true;
        if (newChar(0, copy) == true){
            out.push_back(copy[0]);
            cost+=appendCost;
            copy = copy.substr(1, copy.size()-1);
            checking = false;
            cout << copy << " copy\n";
        }
        
        
        int len = 1;
        string prev = "";

        while (checking == true){
            temp = copy.substr(0,len);
            cout << temp << " = "<<copy << " temp\n";
            if (out.find(temp) != -1){               
                cout << "hmm\n";                
                if (temp == copy){
                    cout << "here\n";
                    out.append(temp);
                    copy = copy.substr(temp.size(), copy.size());
                    cost+=cloneCost;
                    checking = false;   
                }
                else if (out.find(copy.substr(0,len+1)) == -1){
                    out.push_back(copy[0]);
                    copy = copy.substr(1, copy.size()-1);
                    cost+=appendCost;
                    checking = false;
                }
                prev = temp;
                len++;
                //out.append(temp);
                //cout << out.find(temp) <<" ASN";
                //break;
            }
            else if (temp.size() >1 && out.find(prev) != -1){
                cout << " no here\n";
                out.append(temp);
                copy = copy.substr(temp.size(), copy.size());
                cost+=cloneCost;
                checking = false;                
            }
            else{
                cout << " mayb here\n";
                out.push_back(copy[0]);
                copy = copy.substr(1, copy.size()-1);
                cost+=appendCost;
                checking = false;
            }
        }
    }




    /*while (input[pos+1]){
        pos++;
        if (newChar(pos, input)){
            pos++;
            out.push_back(input[pos]);
            existChar.push_back(input[pos]);
            cost +=appendCost;
        }
        else{
            int len = 1;
            while(true){
                if(pos+len != input.size()-1){
                   temp = input.substr(pos, len);
                    
                    if(temp.size()>1){
                        temp = temp.substr(pos,temp.size()-1);
                        out.append(temp);
                        cost+=cloneCost;
                        pos+=temp.size()-1;
                        break;
                    }
                    else if (out.find(temp)==true){
                        len++;
                    }
                    else{
                        if (!newChar(pos, input)){
                            cout << temp << "old\n";
                            len++;
                        }
                        else{
                            cout << " done\n";
                            out.push_back(input[pos]);
                            cost+= appendCost;
                            break;  
                        }
                    }
                    
                 
                }
                else{
                    temp = temp.substr(0,temp.size());
                    subStrings.push_back(temp);
                    out.append(temp);
                    cost+=cloneCost;
                    pos+=temp.size();
                    break;
                }
                
            }

        }*/
        /*else{
            int len = 1;
            //cout << input.substr(pos, 1)<< " sdkjvnsdvsk\n";
            while(true){
                temp = input.substr(pos, len);
                if (out.find(temp)){ 
                    cout << pos << " pos\n";
                    cout << temp << "111\n";
                    len++;
                }
                else if(temp.size()>1){
                    cout << temp << " temp";
                    temp = temp.substr(0,temp.size()-1);
                    subStrings.push_back(temp);
                    out.append(temp);
                    cost+=cloneCost;
                    pos+=temp.size();
                    cout << pos << " pos\n";
                    break;
                }
                else{
                    if (!newChar(pos, input)){
                        cout << "old\n";
                        len++;
                    }
                    else{
                        cout << " done\n";
                        out.push_back(input[pos]);
                        cost+= appendCost;
                        break;  
                    }
                    
                }
            


            }


            break;
        }
    }*/
    
    return cost;
    
}





// do not write or edit anything below this line

#endif
