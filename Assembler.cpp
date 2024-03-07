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
unordered_map <string ,string > ins_type ={
  {"add","R"},{"and","R"},
 {"or","R"},{"sll","R"},{"slt","R"},{"sra","R"},{"srl","R"},{"sub","R"},{"xor","R"},{"mul","R"},{"div","R"},{"rem","R"},
 {"addi","I"},{"andi","I"},{"ori","I"},{"lb","I"},{"ld","I"},{"lh","I"},{"lw","I"},{"jalr","I"},
 {"sb","S"},{"sw","S"},{"sd","S"},{"sh","S"},
 {"beq","SB"},{"bne","SB"},{"bge","SB"},{"blt","SB"},
 {"auipc","U"},{"lui","U"},
 {"jal","UJ"}
};

string hex2bin(string &h, int length){
  string a,b;
  
    int i=0;
    while(i<8){
      switch(h[i]){
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
  while(b.size()<length)
      {b = "0" + b;}
  return b;
}

string bintohex(string &s){
  bitset<32>bintohex(s);
  unsigned int intValue = bintohex.to_ulong();
  stringstream hexStream;
  hexStream<<hex<<intValue;
  string hexString = hexStream.str();
   int l = 8 - hexString.length();
  string b(l,'0');
  b+=hexString;
  b.insert(0,"0x");
  return b;
}

 int codeaddress = 0x00000000; //Address of code segment 
   int dataaddress= 0x10000000; //Address of data segment 
   int heapaddress = 0x10008000; //Address of heap segment
   int stackaddress = 0x7FFFFFDC; //Address of stack segment

string Rformat(string instruction, string rs2, string rs1, string rd) //For R format instructions 
{
  string bin = "";
  bin = bin + funct7[instruction];
  bin = bin + rs2;
  
  bin = bin + rs1;
  bin = bin + funct3[instruction];
  bin = bin + rd;
  bin = bin + opcode[instruction];
 
  string hex  = bintohex(bin);
  return hex;
}


string Iformat(string instruction, string immediate, string rs1, string rd) //For I format instructions
{
  string bin = "";
  bin = bin + immediate;
  bin = bin + rs1;
  bin = bin + funct3[instruction];
  bin = bin + rd;
  bin = bin + opcode[instruction];
  cout<<bin<<endl;
  string hex  = bintohex(bin);
 return hex;
}

string Sformat(string instruction, string rs2, string rs1, string immediate) //For S format instructions
{
 string bin = "";
  bin = bin + immediate[0] + immediate[1] + immediate[2] + immediate[3] + immediate[4] + immediate[5] + immediate[6] ;
 bin = bin + rs2; 
 bin = bin + rs1;
  bin = bin + funct3[instruction];
   bin = bin + immediate[7] + immediate[8] + immediate[9] + immediate[10] + immediate[11] ;
  bin = bin + opcode[instruction];
  string hex  = bintohex(bin);
 return hex;
}


string SBformat(string instruction, string rs2, string rs1, string immediate) //For SB format instructions
{
 string bin = "";
  bin = bin + immediate[0] + immediate[1] + immediate[2] + immediate[3] + immediate[4] + immediate[5] + immediate[6] ;
 bin = bin + rs2; 
 bin = bin + rs1;
  bin = bin + funct3[instruction];
   bin = bin + immediate[7] + immediate[8] + immediate[9] + immediate[10] + immediate[11] ;
  bin = bin + opcode[instruction];
  string hex  = bintohex(bin);
  return hex;
}

string Uformat(string instruction , string immediate, string rd) //For U format instructions
{
  string bin = "";
  bin = bin + immediate;
  bin = bin + rd;
  bin = bin + opcode[instruction];
  string hex  = bintohex(bin);
  return hex;
}

string UJformat(string instruction , string immediate, string rd) //For UJ format instructions
{
 string bin = "";
  bin = bin + immediate;
  bin = bin + rd;
  bin = bin + opcode[instruction];
  string hex  = bintohex(bin);
  return hex;
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
  

    while(getline(infile,line))
     {
      line = regex_replace(line, regex("^\\s+|\\s+$"),"");//Removing spaces leading or trailing 
      line = regex_replace(line, regex(",")," ");//Removing commas

      if(line.empty())
       {continue;}
       
      if(line[0]=='.') // Prakhar add the code to handle directives
      {}
 

       istringstream iss(line);
       vector<string> tokens;
      for(string token; iss>>token;)
       {
        tokens.push_back(token);
       }
      
       

      string inst = ins_type[tokens[0]];
      string machinecode;
      if(inst=="R")
      {
        machinecode = Rformat(tokens[0], registers[tokens[3]],registers[tokens[2]],registers[tokens[1]]);
        outfile <<"0x"<<hex<<codeaddress<< " "<<machinecode<<endl;
        codeaddress += 4;  
      }
      else if(inst=="I")
            {
               machinecode =  Iformat(tokens[0], dec2bin(tokens[3], 12),registers[tokens[2]],registers[tokens[1]]);
               
              outfile <<"0x"<<hex<<codeaddress<< " "<<machinecode<<endl;
              codeaddress += 4; 
            }
            else if(inst=="S")
                  {
                    machinecode =  Sformat(tokens[0], registers[tokens[1]],registers[tokens[3]], dec2bin(tokens[2],12));
                    outfile <<"0x"<<hex<<codeaddress<< " "<<machinecode<<endl;
                    codeaddress += 4; 
                  }
                  else if(inst=="SB")
                        {
                          machinecode =  SBformat(tokens[0], registers[tokens[2]],registers[tokens[1]], dec2bin(tokens[1],12));
                          outfile <<"0x"<<hex<<codeaddress<< " "<<machinecode<<endl;
                          codeaddress += 4; 
                        }
                        else if(inst=="U")
                              {
                                machinecode =  Uformat(tokens[0], hex2bin(tokens[2],20),registers[tokens[1]]);
                                 outfile <<"0x"<<hex<<codeaddress<< " "<<machinecode<<endl;
                                 codeaddress += 4; 
                              }
                              else if(inst=="UJ")
                                    {
                                       
                                     machinecode=   UJformat(tokens[0], hex2bin(tokens[2],20),registers[tokens[1]]);
                                     outfile <<"0x"<<hex<<codeaddress<< " "<<machinecode<<endl;
                                      codeaddress += 4; 
                                    }
                                    else
                                    {break;}

      
     }
  outfile <<"0x"<<hex<<codeaddress<< " End of program"<<endl;
 infile.close();
 outfile.close();
   
}

int main()
{
assemble("input.asm", "output.mc");

  return 0;
}
