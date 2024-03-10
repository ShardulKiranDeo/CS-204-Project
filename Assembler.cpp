#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> opcode = {
    {"add", "0110011"},
    {"and", "0110011"},
    {"or", "0110011"},
    {"sll", "0110011"},
    {"slt", "0110011"},
    {"sra", "0110011"},
    {"srl", "0110011"},
    {"sub", "0110011"},
    {"xor", "0110011"},
    {"mul", "0110011"},
    {"div", "0110011"},
    {"rem", "0110011"},
    {"addi", "0010011"},
    {"andi", "0010011"},
    {"ori", "0010011"},
    {"lb", "0000011"},
    {"ld", "0000011"},
    {"lh", "0000011"},
    {"lw", "0000011"},
    {"jalr", "1100111"},
    {"sb", "0100011"},
    {"sw", "0100011"},
    {"sd", "0100011"},
    {"sh", "0100011"},
    {"beq", "1100011"},
    {"bne", "1100011"},
    {"bge", "1100011"},
    {"blt", "1100011"},
    {"auipc", "0010111"},
    {"lui", "0110111"},
    {"jal", "1101111"}

};

unordered_map<string, string> registers = {
    {"x0", "00000"},
    {"x1", "00001"},
    {"x2", "00010"},
    {"x3", "00011"},
    {"x4", "00100"},
    {"x5", "00101"},
    {"x6", "00110"},
    {"x7", "00111"},
    {"x8", "01000"},
    {"x9", "01001"},
    {"x10", "01010"},
    {"x11", "01011"},
    {"x12", "01100"},
    {"x13", "01101"},
    {"x14", "01110"},
    {"x15", "01111"},
    {"x16", "10000"},
    {"x17", "10001"},
    {"x18", "10010"},
    {"x19", "10011"},
    {"x20", "10100"},
    {"x21", "10101"},
    {"x22", "10110"},
    {"x23", "10111"},
    {"x24", "11000"},
    {"x25", "11001"},
    {"x26", "11010"},
    {"x27", "11011"},
    {"x28", "11100"},
    {"x29", "11101"},
    {"x30", "11110"},
    {"x31", "11111"}};

unordered_map<string, string> funct3 = {
    {"add", "000"},
    {"and", "111"},
    {"or", "110"},
    {"sll", "001"},
    {"slt", "010"},
    {"sra", "101"},
    {"srl", "101"},
    {"sub", "000"},
    {"xor", "100"},
    {"mul", "000"},
    {"div", "100"},
    {"rem", "110"},
    {"addi", "000"},
    {"andi", "111"},
    {"ori", "110"},
    {"lb", "000"},
    {"ld", "011"},
    {"lh", "001"},
    {"lw", "010"},
    {"jalr", "000"},
    {"sb", "000"},
    {"sw", "010"},
    {"sd", "011"},
    {"sh", "001"},
    {"beq", "000"},
    {"bne", "001"},
    {"bge", "101"},
    {"blt", "100"},

};
unordered_map<string, string> funct7 = {
    {"add", "0000000"},
    {"and", "0000000"},
    {"or", "0000000"},
    {"sll", "0000000"},
    {"slt", "0000000"},
    {"sra", "0100000"},
    {"srl", "0000000"},
    {"sub", "0100000"},
    {"xor", "0000000"},

};
unordered_map<string, string> ins_type = {
    {"add", "R"}, {"and", "R"}, {"or", "R"}, {"sll", "R"}, {"slt", "R"}, {"sra", "R"}, {"srl", "R"}, {"sub", "R"}, {"xor", "R"}, {"mul", "R"}, {"div", "R"}, {"rem", "R"}, {"addi", "I"}, {"andi", "I"}, {"ori", "I"}, {"lb", "I"}, {"ld", "I"}, {"lh", "I"}, {"lw", "I"}, {"jalr", "I"}, {"sb", "S"}, {"sw", "S"}, {"sd", "S"}, {"sh", "S"}, {"beq", "SB"}, {"bne", "SB"}, {"bge", "SB"}, {"blt", "SB"}, {"auipc", "U"}, {"lui", "U"}, {"jal", "UJ"}};

string hex2bin(string &h, int length)
{
    string a, b;

    int i = 0;
    while (i < 8)
    {
        switch (h[i])
        {
        case '0':
            a = "0000";
            break;
        case '1':
            a = "0001";
            break;
        case '2':
            a = "0010";
            break;
        case '3':
            a = "0011";
            break;
        case '4':
            a = "0100";
            break;
        case '5':
            a = "0101";
            break;
        case '6':
            a = "0110";
            break;
        case '7':
            a = "0111";
            break;
        case '8':
            a = "1000";
            break;
        case '9':
            a = "1001";
            break;
        case 'a':
        case 'A':
            a = "1010";
            break;
        case 'b':
        case 'B':
            a = "1011";
            break;
        case 'c':
        case 'C':
            a = "1100";
            break;
        case 'd':
        case 'D':
            a = "1101";
            break;
        case 'e':
        case 'E':
            a = "1110";
            break;
        case 'f':
        case 'F':
            a = "1111";
            break;
        }
        b += a;

        a.clear();
        i++;
    }
    while (b.size() < length)
    {
        b = "0" + b;
    }
    return b;
}

int power(int a)
{
    if (a == 0)
    {
        return 1;
    }
    return 10 * power(a - 1);
}

string dec2bin_data(string &h, int l)
{
    string a;
    int i = 0;
    int sum = 0;
    while (i < l)
    {
        char a = h[l - i - 1];
        int b = a - '0';
        sum += power(i) * b;
        i++;
    }
    while (sum > 0)
    {
        int rem = sum % 2;
        sum = sum / 2;
        char c = rem + '0';
        a += c;
    }
    reverse(a.begin(), a.end());
    return a;
}

string dec2bin(const string &a, int l)
{
    // Convert string to integer
    int num = stoi(a);

    // Initialize result string
    string binary;

    // Convert number to binary
    while (num > 0)
    {
        // Append the least significant bit to the binary string
        binary.insert(binary.begin(), '0' + (num & 1));

        // Shift the number to the right by 1 bit
        num >>= 1;
    }

    // Pad the binary string with leading zeros if necessary
    while (binary.length() < l)
    {
        binary.insert(binary.begin(), '0');
    }

    // Trim the binary string to the desired length
    if (binary.length() > l)
    {
        binary = binary.substr(binary.length() - l);
    }

    return binary;
}

string bintohex(string &s)
{
    bitset<32> bintohex(s);
    unsigned int intValue = bintohex.to_ulong();
    stringstream hexStream;
    hexStream << hex << intValue;
    string hexString = hexStream.str();
    int l = 16 - hexString.length();
    string b(l, '0');
    b += hexString;
    b.insert(0, "0x");
    return b;
}

string bintohex8(string &s)
{
    bitset<32> bintohex(s);
    unsigned int intValue = bintohex.to_ulong();
    stringstream hexStream;
    hexStream << hex << intValue;
    string hexString = hexStream.str();
    int l = 8 - hexString.length();
    string b(l, '0');
    b += hexString;
    b.insert(0, "0x");
    return b;
}

int codeaddress = 0x00000000;  // Address of code segment
int dataaddress = 0x10000000;  // Address of data segment
int heapaddress = 0x10008000;  // Address of heap segment
int stackaddress = 0x7FFFFFDC; // Address of stack segment

string Rformat(string instruction, string rs2, string rs1, string rd) // For R format instructions
{
    string bin = "";
    bin = bin + funct7[instruction];
    bin = bin + rs2;

    bin = bin + rs1;
    bin = bin + funct3[instruction];
    bin = bin + rd;
    bin = bin + opcode[instruction];

    string hex = bintohex8(bin);
    return hex;
}

string Iformat(string instruction, string immediate, string rs1, string rd) // For I format instructions
{
    string bin = "";
    bin = bin + immediate;
    bin = bin + rs1;
    bin = bin + funct3[instruction];
    bin = bin + rd;
    bin = bin + opcode[instruction];
    cout << bin << endl;
    string hex = bintohex8(bin);
    return hex;
}

string Sformat(string instruction, string rs2, string rs1, string immediate) // For S format instructions
{
    string bin = "";
    bin = bin + immediate[0] + immediate[1] + immediate[2] + immediate[3] + immediate[4] + immediate[5] + immediate[6];
    bin = bin + rs2;
    bin = bin + rs1;
    bin = bin + funct3[instruction];
    bin = bin + immediate[7] + immediate[8] + immediate[9] + immediate[10] + immediate[11];
    bin = bin + opcode[instruction];
    string hex = bintohex8(bin);
    return hex;
}

string SBformat(string instruction, string rs2, string rs1, string immediate) // For SB format instructions
{
    string bin = "";
    bin = bin + immediate[0] + immediate[1] + immediate[2] + immediate[3] + immediate[4] + immediate[5] + immediate[6];
    bin = bin + rs2;
    bin = bin + rs1;
    bin = bin + funct3[instruction];
    bin = bin + immediate[7] + immediate[8] + immediate[9] + immediate[10] + immediate[11];
    bin = bin + opcode[instruction];
    string hex = bintohex8(bin);
    return hex;
}

string Uformat(string instruction, string immediate, string rd) // For U format instructions
{
    string bin = "";
    bin = bin + immediate;
    bin = bin + rd;
    bin = bin + opcode[instruction];
    string hex = bintohex8(bin);
    return hex;
}

string UJformat(string instruction, string immediate, string rd) // For UJ format instructions
{
    string bin = "";
    bin = bin + immediate;
    bin = bin + rd;
    bin = bin + opcode[instruction];
    string hex = bintohex8(bin);
    return hex;
}

int check(vector<string> tokens)
{
  auto it = opcode.find(tokens[0]); // check instruction
  if(it==opcode.end())
  {return -1;}

  string inst = ins_type[tokens[0]];
  if(inst=="R")
  { if(tokens.size()!=4)
      {return -1;};
      it = registers.find(tokens[1]); // check registers
      if(it==registers.end())
      {return -1;}
       it = registers.find(tokens[2]); 
      if(it==registers.end())
      {return -1;}
       it = registers.find(tokens[3]); 
      if(it==registers.end())
      {return -1;}
  }
  else if(inst=="I")
        {
            if(tokens.size()!=4)
              {return -1;};
            it = registers.find(tokens[1]); // check registers
            if(it==registers.end())
            { return -1;}
            it = registers.find(tokens[2]); 
            if(it==registers.end())
            {return -1;}
            for (char ch : tokens[3]) {
                if (!isdigit(ch)) //Check if each character is a digit
                 {return -1;}
            }
           
        }
        else if(inst=="S")
              {

              }
              else if(inst=="SB")
                {

                }
                else if(inst=="U")
                      {

                      }
                      else if(inst=="UJ")
                          {

                          }
}

void assemble(string inputf, string outputf) // Function to take input and write into the output file
{
    ifstream infile(inputf);
    ofstream outfile(outputf);

    if (!infile.is_open() || !outfile.is_open())
    {
        cout << "Error opening files" << endl;
        return;
    }
    string line;

    while (getline(infile, line))
    {
        line = regex_replace(line, regex("^\\s+|\\s+$"), ""); // Removing spaces leading or trailing
        line = regex_replace(line, regex(","), " ");          // Removing commas

        if (line.empty())
        {
            continue;
        }

        if (line[0] == '.')
        {
            istringstream iss(line);
            string token;
            iss >> token;
           if (token == ".text")
            {
                while (getline(infile, line))
                {

                    line = regex_replace(line, regex("^\\s+|\\s+$"), ""); // Removing spaces leading or trailing
                    line = regex_replace(line, regex(","), " ");          // Removing commas
                    istringstream isstream(line);
                    string token_2;
                    isstream >> token_2;
                    cout << token_2 << endl;
                    if (token_2 == ".data")
                    {
                        // Implement for .data
                        token = ".data";
                        break;
                    }

                    istringstream iss(line);
                    vector<string> tokens;
                    for (string token; iss >> token;)
                    {
                        tokens.push_back(token);
                    }


                    int ch = check(tokens);
                  

                    if(ch==-1)
                  {cout<<"Syntax Error"<<endl;
                  return ;}

                    string inst = ins_type[tokens[0]];
                    string machinecode;
                    if (inst == "R")
                    {
                        machinecode = Rformat(tokens[0], registers[tokens[3]], registers[tokens[2]], registers[tokens[1]]);
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "I")
                    {
                        string a_token = "";
                        string b_token = "";
                        string c_token;
                        string d_token;

                        string concatenated;

                        for (int index = 2; index < tokens.size(); index++)
                        {
                            concatenated += tokens[index];
                        }
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), ' '), concatenated.end());
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), '{'), concatenated.end());
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), '}'), concatenated.end());
                        int index = 0;
                        for (index = 0; index < concatenated.size(); index++)
                        {
                            if (concatenated[index] == '(')
                            {
                                break;
                            }
                            a_token += concatenated[index];
                        }
                        index++;
                        for (; index < concatenated.size(); index++)
                        {
                            if (concatenated[index] == ')')
                            {
                                break;
                            }
                            b_token += concatenated[index];
                        }

                        cout << a_token << " " << b_token << endl;

                        if ((tokens[0] == "lw") || (tokens[0] == "lb") || (tokens[0] == "lh") || (tokens[0] == "ld") || (tokens[0] == "jalr"))
                        {
                            machinecode = Iformat(tokens[0], dec2bin(a_token, 12), registers[b_token], registers[tokens[1]]);
                        }
                        else
                        {
                            machinecode = Iformat(tokens[0], dec2bin(tokens[3], 12), registers[tokens[2]], registers[tokens[1]]);
                            cout << machinecode << endl;
                        }

                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "S")
                    {
                        string a_token = "";
                        string b_token = "";
                        string c_token;
                        string d_token;

                        string concatenated;

                        for (int index = 2; index < tokens.size(); index++)
                        {
                            concatenated += tokens[index];
                        }
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), ' '), concatenated.end());
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), '{'), concatenated.end());
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), '}'), concatenated.end());
                        int index = 0;
                        for (index = 0; index < concatenated.size(); index++)
                        {
                            if (concatenated[index] == '(')
                            {
                                break;
                            }
                            a_token += concatenated[index];
                        }
                        index++;
                        for (; index < concatenated.size(); index++)
                        {
                            if (concatenated[index] == ')')
                            {
                                break;
                            }
                            b_token += concatenated[index];
                        }

                        
                        machinecode = Sformat(tokens[0], registers[tokens[1]], registers[b_token], dec2bin(a_token, 12));
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "SB")
                    {
                        machinecode = SBformat(tokens[0], registers[tokens[2]], registers[tokens[1]], dec2bin(tokens[3], 12));
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "U")
                    {
                        machinecode = Uformat(tokens[0], dec2bin(tokens[2], 20), registers[tokens[1]]);
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "UJ")
                    {

                        machinecode = UJformat(tokens[0], dec2bin(tokens[2], 20), registers[tokens[1]]);
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else
                    {
                        break;
                    }
                }

                // Decode the instructions
            }
            if (token == ".data") // Writing to the output file in big endian format
            {
                outfile << endl;
                outfile << "  Address "
                        << " "
                        << "+0"
                        << " "
                        << "+1"
                        << " "
                        << "+2"
                        << " "
                        << "+3" << endl;
                int count_of_bytes = 0;
                int data_address_temporary = dataaddress;
                outfile << "0x" << hex << data_address_temporary << " ";
                while (getline(infile, line))
                {
                    line = regex_replace(line, regex("^\\s+|\\s+$"), ""); // Removing spaces leading or trailing
                    line = regex_replace(line, regex(","), " ");          // Removing commas

                    if (line.empty())
                    {
                        continue;
                    }
                    istringstream iss(line);
                    vector<string> data_tokens;
                    string token_temp;
                    for (string token; iss >> token_temp;)
                    {
                        data_tokens.push_back(token_temp);
                    }

                    if (data_tokens[0] == ".text")
                    {
                        token = ".text";
                        outfile << endl;
                        outfile << endl;
                        break;
                    }

                    if (data_tokens[0] == ".byte")
                    {
                        int size_dt = data_tokens.size();
                        for (int i = 1; i < size_dt; i++)
                        {
                            string data_token_temporary = data_tokens[i];
                            int length_dtt = data_token_temporary.size();
                            string binary_data_token_temporary = dec2bin_data(data_token_temporary, length_dtt);
                            string binary_data_token_temporary2 = bintohex(binary_data_token_temporary);
                            outfile << binary_data_token_temporary2.substr(binary_data_token_temporary2.size() - 2) << " ";
                            count_of_bytes += 1;
                            if (count_of_bytes == 4)
                            {
                                count_of_bytes = 0;
                                data_address_temporary += 4;
                                outfile << endl;
                                outfile << "0x" << hex << data_address_temporary << " ";
                            }
                        }
                    }
                    else if (data_tokens[0] == ".half")
                    {
                        int size_dt = data_tokens.size();
                        vector<string> output_memory;
                        for (int i = 1; i < size_dt; i++)
                        {
                            string data_token_temporary = data_tokens[i];
                            int length_dtt = data_token_temporary.size();
                            string binary_data_token_temporary = dec2bin_data(data_token_temporary, length_dtt);
                            string binary_data_token_temporary2 = bintohex(binary_data_token_temporary);
                            int it = 1;
                            while (it < 3)
                            {
                                output_memory.push_back(binary_data_token_temporary2.substr(binary_data_token_temporary2.size() - 2 * it, 2));
                                it++;
                            }
                        }
                        int size_om = output_memory.size();
                        for (int i = 0; i < size_om; i++)
                        {
                            outfile << output_memory[i] << " ";
                            count_of_bytes++;
                            if (count_of_bytes == 4)
                            {
                                count_of_bytes = 0;
                                data_address_temporary += 4;
                                outfile << endl;
                                outfile << "0x" << hex << data_address_temporary << " ";
                            }
                        }
                    }
                    else if (data_tokens[0] == ".word")
                    {
                        int size_dt = data_tokens.size();
                        vector<string> output_memory;
                        for (int i = 1; i < size_dt; i++)
                        {
                            string data_token_temporary = data_tokens[i];
                            int length_dtt = data_token_temporary.size();
                            string binary_data_token_temporary = dec2bin_data(data_token_temporary, length_dtt);
                            string binary_data_token_temporary2 = bintohex(binary_data_token_temporary);
                            int it = 1;
                            while (it < 5)
                            {
                                output_memory.push_back(binary_data_token_temporary2.substr(binary_data_token_temporary2.size() - 2 * it, 2));
                                it++;
                            }
                        }
                        int size_om = output_memory.size();
                        for (int i = 0; i < size_om; i++)
                        {
                            outfile << output_memory[i] << " ";
                            count_of_bytes++;
                            if (count_of_bytes == 4)
                            {
                                count_of_bytes = 0;
                                data_address_temporary += 4;
                                outfile << endl;
                                outfile << "0x" << hex << data_address_temporary << " ";
                            }
                        }
                    }
                    else if (data_tokens[0] == ".dword")
                    {
                        int size_dt = data_tokens.size();
                        vector<string> output_memory;
                        for (int i = 1; i < size_dt; i++)
                        {
                            string data_token_temporary = data_tokens[i];
                            int length_dtt = data_token_temporary.size();
                            string binary_data_token_temporary = dec2bin_data(data_token_temporary, length_dtt);
                            string binary_data_token_temporary2 = bintohex(binary_data_token_temporary);
                            int it = 1;
                            while (it < 9)
                            {
                                output_memory.push_back(binary_data_token_temporary2.substr(binary_data_token_temporary2.size() - 2 * it, 2));
                                it++;
                            }
                        }
                        int size_om = output_memory.size();
                        for (int i = 0; i < size_om; i++)
                        {
                            outfile << output_memory[i] << " ";
                            count_of_bytes++;
                            if (count_of_bytes == 4)
                            {
                                count_of_bytes = 0;
                                data_address_temporary += 4;
                                outfile << endl;
                                outfile << "0x" << hex << data_address_temporary << " ";
                            }
                        }
                    }
                    else if (data_tokens[0] == ".asciiz")
                    {
                        int size_dt = data_tokens.size();
                        for (int i = 1; i < size_dt; i++)
                        {
                            string temporary_string_asciiz = data_tokens[i];
                            temporary_string_asciiz.erase(remove(temporary_string_asciiz.begin(), temporary_string_asciiz.end(), '"'), temporary_string_asciiz.end());
                            int size_tas = temporary_string_asciiz.size();
                            cout << temporary_string_asciiz << endl;
                            for (int j = 0; j < size_tas; j++)
                            {
                                count_of_bytes++;
                                char ch = temporary_string_asciiz[j];
                                int value_ch = ch;
                                outfile << hex << setw(2) << setfill('0') << value_ch << " ";
                                if (count_of_bytes == 4)
                                {
                                    count_of_bytes = 0;
                                    data_address_temporary += 4;
                                    outfile << endl;
                                    outfile << "0x" << hex << data_address_temporary << " ";
                                }
                            }
                            int filler_value = 0;
                            outfile << hex << setw(2) << setfill('0') << filler_value << " ";
                            count_of_bytes++;
                            if (count_of_bytes == 4)
                            {
                                count_of_bytes = 0;
                                data_address_temporary += 4;
                                outfile << endl;
                                outfile << "0x" << hex << data_address_temporary << " ";
                            }
                        }
                    }
                }
            }
            if (token == ".text")
            {
                while (getline(infile, line))
                {

                    line = regex_replace(line, regex("^\\s+|\\s+$"), ""); // Removing spaces leading or trailing
                    line = regex_replace(line, regex(","), " ");          // Removing commas
                    istringstream isstream(line);
                    string token_2;
                    isstream >> token_2;
                    cout << token_2 << endl;
                    if (token_2 == ".data")
                    {
                        // Implement for .data
                        token = ".data";
                        break;
                    }

                    istringstream iss(line);
                    vector<string> tokens;
                    for (string token; iss >> token;)
                    {
                        tokens.push_back(token);
                    }

                    string inst = ins_type[tokens[0]];
                    string machinecode;
                    if (inst == "R")
                    {
                        machinecode = Rformat(tokens[0], registers[tokens[3]], registers[tokens[2]], registers[tokens[1]]);
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "I")
                    {
                        string a_token = "";
                        string b_token = "";
                        string c_token;
                        string d_token;

                        string concatenated;

                        for (int index = 2; index < tokens.size(); index++)
                        {
                            concatenated += tokens[index];
                        }
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), ' '), concatenated.end());
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), '{'), concatenated.end());
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), '}'), concatenated.end());
                        int index = 0;
                        for (index = 0; index < concatenated.size(); index++)
                        {
                            if (concatenated[index] == '(')
                            {
                                break;
                            }
                            a_token += concatenated[index];
                        }
                        index++;
                        for (; index < concatenated.size(); index++)
                        {
                            if (concatenated[index] == ')')
                            {
                                break;
                            }
                            b_token += concatenated[index];
                        }

                        cout << a_token << " " << b_token << endl;

                        if ((tokens[0] == "lw") || (tokens[0] == "lb") || (tokens[0] == "lh") || (tokens[0] == "ld") || (tokens[0] == "jalr"))
                        {
                            machinecode = Iformat(tokens[0], dec2bin(a_token, 12), registers[b_token], registers[tokens[1]]);
                        }
                        else
                        {
                            machinecode = Iformat(tokens[0], dec2bin(tokens[3], 12), registers[tokens[2]], registers[tokens[1]]);
                            cout << machinecode << endl;
                        }

                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "S")
                    {
                        string a_token = "";
                        string b_token = "";
                        string c_token;
                        string d_token;

                        string concatenated;

                        for (int index = 2; index < tokens.size(); index++)
                        {
                            concatenated += tokens[index];
                        }
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), ' '), concatenated.end());
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), '{'), concatenated.end());
                        concatenated.erase(std::remove(concatenated.begin(), concatenated.end(), '}'), concatenated.end());
                        int index = 0;
                        for (index = 0; index < concatenated.size(); index++)
                        {
                            if (concatenated[index] == '(')
                            {
                                break;
                            }
                            a_token += concatenated[index];
                        }
                        index++;
                        for (; index < concatenated.size(); index++)
                        {
                            if (concatenated[index] == ')')
                            {
                                break;
                            }
                            b_token += concatenated[index];
                        }

                        
                        machinecode = Sformat(tokens[0], registers[tokens[1]], registers[b_token], dec2bin(a_token, 12));
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "SB")
                    {
                        machinecode = SBformat(tokens[0], registers[tokens[2]], registers[tokens[1]], dec2bin(tokens[1], 12));
                     
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "U")
                    {
                        machinecode = Uformat(tokens[0], dec2bin(tokens[2], 20), registers[tokens[1]]);
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else if (inst == "UJ")
                    {

                        machinecode = UJformat(tokens[0], dec2bin(tokens[2], 20), registers[tokens[1]]);
                        outfile << "0x" << hex << codeaddress << " " << machinecode << endl;
                        codeaddress += 4;
                    }
                    else
                    {
                        break;
                    }
                }

                // Decode the instructions
            }
        }
    }
}

int main()
{
    assemble("input.asm", "output.mc");
    return 0;
}
