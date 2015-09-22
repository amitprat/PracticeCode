/*
Taken from careercup
Given two strings, return boolean True/False, if they are only one edit apart.Edit can be insert/delete/update of only one character in the string. Eg: 

-True 
xyz,xz 
xyz, xyk 
xy, xyz 


-False 
xyz, xyz 
xyz,xzy 
x, xyz
*/


bool edit(string s1, string s2) {
    if(s2.size() < s1.size()) {
        return edit(s2, s1);
    }    
    if(s1.size() + 1 < s2.size()) {
        return false;
    }   

    int i = 0;
    while(i < s1.size()) {
        if(s1[i] != s2[i]) {
            if(s1.size() == s2.size()) {
                return s1.substr(i+1) == s2.substr(i+1);
            }else {
                return s1.substr(i) == s2.substr(i+1);
            }   
        }   
        i ++; 
    }   
    return s1.size() != s2.size();
}
