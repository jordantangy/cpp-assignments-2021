#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;

namespace ariel{

const vector<string> hats = {"_===_"," ___ \n.....","   _ \n  /_\\"," ___ \n(_*_)"};
const vector<string> noses = {",",".","_"," "};
const vector<string> eyes = {".","o","O","-"};
const vector<string> leftArms = {"<","\\","/",""};
const vector<string> rightArms = {">","/","\\",""};
const vector<string> torsos = {":","] [","> <", "   "};
const vector<string> bases = {":","\" \"","___",""};

string makeHead(char head){
        int index = (head-'0')-1;
        return hats[index]+'\n' ; 
}
string makeEyesAndNose(char nose,char l_Eye,char r_Eye){
        int noseIndex = (nose -'0')-1;
        int leftEye_i = (l_Eye-'0')-1;
        int rightEye_i = (r_Eye-'0')-1;
        string Nose = noses[noseIndex];
        string left = eyes[leftEye_i];
        string right = eyes[rightEye_i];
        return "("+left+Nose+right+")"+'\n';
}
string insertTorso(char t){
        int torso_i = (t-'0')-1;
        string tor = torsos[torso_i];
        string space = " ";
        if(tor == ":" || tor.empty()){
                 return "("+space+tor+space+")"+'\n';
        }
        
        return "("+tor+")"+'\n';

}
string insertBase(char num){
        int base_i = (num-'0')-1;
        string ba = bases[base_i];
        string space = " ";
        if (ba == ":"){
                return "("+space+ba+space+")";
        }
        if(ba.empty()){
                return "("+space+ba+space+space+")";
        }
        
        return "("+ba+")";
        
}

string snowman(int num){
    string number = to_string(num);
    string e= "Invalid code ";
    if(number.length() < 8 || number.length() > 8){
      throw  invalid_argument(e + "'" + to_string(num) + "'");
    }
    for (int i = 0 ; i< number.length() ; i++){
        int a = number[i]-'0';
        if(a <1 || a > 4){
          throw  invalid_argument(e + "'" + to_string(num) + "'");
        }
    }
    string head = makeHead(number[0]);
    string eyesandNose = makeEyesAndNose(number[1],number[2],number[3]);
    string tor = insertTorso(number[6]);
    string base = insertBase(number[7]);

    //check left up arm:
    if (number[4] == '2'){
      eyesandNose = leftArms[(number[4]-'0')-1] + eyesandNose;
    }
    //check right up arm:
    if (number[5] == '2'){
      eyesandNose.erase(eyesandNose.size() - 1);
      eyesandNose += rightArms[(number[5]-'0')-1] + '\n';
    }
    //check torso down left arm:
    if (number[4] == '3' || number[4] == '1' || number[4] == '4'){
      tor = leftArms[(number[4]-'0')-1] + tor;
    }
    //check torso down right arm:
    if (number[5] == '3' || number[5] == '1' || number[5] == '4'){
      tor.erase(tor.size() - 1);
      tor += rightArms[(number[5]-'0')-1]+'\n';
    }
    string snowm = head+eyesandNose+tor+base;
    return snowm;
  }


}



