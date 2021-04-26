string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
void letters(string digits, string out, vector<string>& output){
  if(digits.empty()){
     output.push_back(out);
     return;
  }
  string s = arr[digits[0]-'0'];
  for(int i=0; i<s.length(); i++){
     letters(digits.substr(1), out+s[i], output);
  }
}
    
vector<string> letterCombinations(string digits) {
  if(digits.empty()){
     return {};
  }
  vector<string> output;
  letters(digits ,"" , output);
  return output;
}
