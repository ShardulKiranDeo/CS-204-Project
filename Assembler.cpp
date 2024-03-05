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
 // {"mul",""},
 // {"div",""},
 // {"rem",""},
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

};
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

};

void Rformat(string instruction, string rs2, string rs1, string rd) //For R format instructions 
{
  string bin = "";
  bin = bin + funct7[instruction];
  bin = bin + registers[rs2];
  bin = bin + registers[rs1];
  bin = bin + funct3[instruction];
  bin = bin + registers[rd];
  bin = bin + opcode[instruction];
  string hex  = bintohex(bin);
 
}


void Iformat(string instruction, string immediate, string rs1, string rd) //For I format instructions
{
  string bin = "";
  bin = bin + immediate;
  bin = bin + registers[rs1];
  bin = bin + funct3[instruction];
  bin = bin + registers[rd];
  bin = bin + opcode[instruction];
  string hex  = bintohex(bin);
 
}

void Sformat(string instruction) //For S format instructions
{
 
 
}


void SBformat(string instruction) //For SB format instructions
{
 
}

void Uformat(string instruction , string immediate, string rd) //For U format instructions
{
  string bin = "";
  bin = bin + immediate;
  bin = bin + registers[rd];
  bin = bin + opcode[instruction];
  string hex  = bintohex(bin);
}

void UJformat(string instruction , string immediate, string rd) //For UJ format instructions
{
 string bin = "";
  bin = bin + immediate;
  bin = bin + registers[rd];
  bin = bin + opcode[instruction];
  string hex  = bintohex(bin);
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
  string line;
   int codeaddress = 0x00000000; //Address of code segment 
   int dataaddress= 0x10000000; //Address of code segment 
   int stackaddress = 0x10008000; //Address of code segment 

    while(getline(infile,line))
     {
       
      
     }
   
}

int main()
{
assemble("input.asm", "output.mc");

  return 0;
}
