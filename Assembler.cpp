#include <iostream>
#include <unordered_map>
#include <fstream>
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
