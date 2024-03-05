#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> opcode = {
 {"add","0110011"},
 {"and","0110011"},
 {"or","0110011"},
 {"sll","0110011"},
 {"slt","0110011"},
 {"sra","0110011"},
 {"srl","0110011"},
 {"sub","0110011"},
 {"xor","0110011"},
 {"mul","0110011"},
 {"div","0110011"},
 {"rem","0110011"},
 {"addi","0010011"},
 {"andi","0010011"},
 {"ori","0010011"},
 {"lb","0000011"},
 {"ld","0000011"},
 {"lh","0000011"},
 {"lw","0000011"},
 {"jalr","1100111"},
 {"sb","0100011"},
 {"sw","0100011"},
 {"sd","0100011"},
 {"sh","0100011"},
 {"beq","1100011"},
 {"bne","1100011"},
 {"bge","1100011"},
 {"blt","1100011"},
 {"auipc","0010111"},
 {"lui","0110111"},
 {"jal","1101111"}

};

unordered_map<string,string> registers={
 {"x0","00000"},
 {"x1","00001"},
 {"x2","00010"},
 {"x3","00011"},
 {"x4","00100"},
 {"x5","00101"},
 {"x6","00110"},
 {"x7","00111"},
 {"x8","01000"},
 {"x9","01001"},
 {"x10","01010"},
 {"x11","01011"},
 {"x12","01100"},
 {"x13","01101"},
 {"x14","01110"},
 {"x15","01111"},
 {"x16","10000"},
 {"x17","10001"},
 {"x18","10010"},
 {"x19","10011"},
 {"x20","10100"},
 {"x21","10101"},
 {"x22","10110"},
 {"x23","10111"},
 {"x24","11000"},
 {"x25","11001"},
 {"x26","11010"},
 {"x27","11011"},
 {"x28","11100"},
 {"x29","11101"},
 {"x30","11110"},
 {"x31","11111"}
};

unordered_map <string,string> funct3 = {
  {"add","000"},
 {"and","111"},
 {"or","110"},
 {"sll","001"},
 {"slt","010"},
 {"sra","101"},
 {"srl","101"},
 {"sub","000"},
 {"xor","100"},
 {"mul","000"},
 {"div","100"},
 {"rem","110"},
 {"addi","000"},
 {"andi","111"},
 {"ori","110"},
 {"lb","000"},
 {"ld","011"},
 {"lh","001"},
 {"lw","010"},
 {"jalr","000"},
 {"sb","000"},
 {"sw","010"},
 {"sd","011"},
 {"sh","001"},
 {"beq","000"},
 {"bne","001"},
 {"bge","101"},
 {"blt","100"},
//  {"auipc",""},
//  {"lui","0110111"},
//  {"jal","1101111"}

}
unordered_map <string,string> funct7={
  {"add","0000000"},
 {"and","0000000"},
 {"or","0000000"},
 {"sll","0000000"},
 {"slt","0000000"},
 {"sra","0100000"},
 {"srl","0000000"},
 {"sub","0100000"},
 {"xor","0000000"},

}

unordered_map <string ,string > ins_type ={
  {"add","R"},{"and","R"},
 {"or","R"},{"sll","R"},{"slt","R"},{"sra","R"},{"srl","R"},{"sub","R"},{"xor","R"},{"mul","R"},{"div","R"},{"rem","R"},
 {"addi","I"},{"andi","I"},{"ori","I"},{"lb","I"},{"ld","I"},{"lh","I"},{"lw","I"},{"jalr","I"},
 {"sb","S"},{"sw","S"},{"sd","S"},{"sh","S"},
 {"beq","SB"},{"bne","SB"},{"bge","SB"},{"blt","SB"},
 {"auipc","U"},{"lui","U"},
 {"jal","UJ"}
}

string hex2bin(string &h){
  string a,b;
  if(h[0] == '0' && h[1] =='x'){
    int i=0;
    while(i<8){
      switch(h[i+2]){
        case '0' : a = "0000"; break;
        case '1' : a = "0001"; break;
        case '2' : a = "0010"; break;
        case '3' : a = "0011"; break;
        case '4' : a = "0100"; break;
        case '5' : a = "0101"; break;
        case '6' : a = "0110"; break;
        case '7' : a = "0111"; break;
        case '8' : a = "1000"; break;
        case '9' : a = "1001"; break;
        case 'a' : case 'A' : a = "1010"; break;
        case 'b' : case 'B' : a = "1011"; break;
        case 'c' : case 'C' : a = "1100"; break;
        case 'd' : case 'D' : a = "1101"; break;
        case 'e' : case 'E' : a = "1110"; break;
        case 'f' : case 'F' : a = "1111"; break;   
      }
      b+=a;
       a.clear();
      i++;
    }
  }
  return b;
}

void Rformat() //For R format instructions 
{

 
}


void Iformat() //For I format instructions
{

 
}

void Sformat() //For I format instructions
{

 
}


void SBformat() //For SB format instructions
{
 
}

void Uformat() //For U format instructions
{
 
}

void UJformat() //For UJ format instructions
{
 
}


void assemble(string inputf, string outputf) //Function to take input and write into the output file
{
   ifstream infile(inputf);
   ofstream outfile(outputf);
   
   if(!infile.is_open() || !outfile.is_open())
   {
     cout<<"Error opening files"<<endl;
     return ;
   }

   
}

int main()
{
assemble("input.asm", "output.mc");

  return 0;
}

