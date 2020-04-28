#include<bits/stdc++.h>
using namespace std;
string entityParser(string text) {
    string temp = "";
    int i = 0;
    while(i < text.length()){
        if(text[i] == '&'){
            if(i+3 < text.length()){
                if(i+4 < text.length()){
                    if(i+5 < text.length()){
                        if(i+6 < text.length()){
                            //&frasl;
                            if(text[i+1] == 'f' && text[i+2] == 'r' && text[i+3] == 'a' && text[i+4] == 's' && text[i+5] == 'l' && text[i+6] == ';'){
                                temp += "/";
                                i += 7;
                                continue;
                            }
                            if(text[i+1] == 'q' && text[i+2] == 'u' && text[i+3] == 'o' && text[i+4] == 't' && text[i+5] == ';'){
                                temp += "\"";
                                i += 6;
                                continue;
                            }
                            if(text[i+1] == 'a' && text[i+2] == 'p' && text[i+3] == 'o' && text[i+4] == 's' && text[i+5] == ';'){
                                temp += "\'";
                                i += 6;
                                continue;
                            }
                            if(text[i+1] == 'a' && text[i+2] == 'm' && text[i+3] == 'p' && text[i+4] == ';'){
                                temp += "&";
                                i += 5;
                                continue;
                            }
                            if(text[i+1] == 'l' && text[i+2] == 't' && text[i+3] == ';'){
                                temp += "<";
                                i += 4;
                                continue;
                            }
                            else if(text[i+1] == 'g' && text[i+2] == 't' && text[i+3] == ';'){
                                temp += ">";
                                i += 4;
                                continue;
                            }
                            else{
                                temp += text[i];
                                i++;
                            }
                        }
                        else{
                            //&quot; &apos;
                            if(text[i+1] == 'q' && text[i+2] == 'u' && text[i+3] == 'o' && text[i+4] == 't' && text[i+5] == ';'){
                                temp += "\"";
                                i += 6;
                                continue;
                            }
                            if(text[i+1] == 'a' && text[i+2] == 'p' && text[i+3] == 'o' && text[i+4] == 's' && text[i+5] == ';'){
                                temp += "\'";
                                i += 6;
                                continue;
                            }
                            if(text[i+1] == 'a' && text[i+2] == 'm' && text[i+3] == 'p' && text[i+4] == ';'){
                                temp += "&";
                                i += 5;
                                continue;
                            }
                            if(text[i+1] == 'l' && text[i+2] == 't' && text[i+3] == ';'){
                                temp += "<";
                                i += 4;
                                continue;
                            }
                            if(text[i+1] == 'g' && text[i+2] == 't' && text[i+3] == ';'){
                                temp += ">";
                                i += 4;
                                continue;
                            }
                            else{
                                temp += text[i];
                                i++;
                            }
                        }
                    }
                    else{
                        //&amp;
                        if(text[i+1] == 'a' && text[i+2] == 'm' && text[i+3] == 'p' && text[i+4] == ';'){
                            temp += "&";
                            i += 5;
                            continue;
                        }
                        if(text[i+1] == 'l' && text[i+2] == 't' && text[i+3] == ';'){
                            temp += "<";
                            i += 4;
                            continue;
                        }
                        if(text[i+1] == 'g' && text[i+2] == 't' && text[i+3] == ';'){
                            temp += ">";
                            i += 4;
                            continue;
                        }
                        else{
                            temp += text[i];
                            i++;
                        }
                    }
                }
                else{
                    if(text[i+1] == 'l' && text[i+2] == 't' && text[i+3] == ';'){
                        temp += "<";
                        i += 4;
                    }
                    else if(text[i+1] == 'g' && text[i+2] == 't' && text[i+3] == ';'){
                        temp += ">";
                        i += 4;
                    }
                    else{
                        temp += text[i];
                        i++;
                    }
                }
            }
            else{
                temp += text[i];
                i++;
            }
        }
        else{
            temp += text[i];
            i++;
        }
    }
    return temp;
}
int main() {
    std::cout << entityParser("and I quote: &quot;...&lt;");
}

