#include <fstream>
#include <iostream>
#include <string>

int open_stream(std::string file, std::string flag, std::ifstream &input, std::ofstream &output)
{
    if (flag == "input")
    {
        (void)output;
        input.open(file);
        if (!input.is_open())
        {
            std::cout << flag << " file could not be opened\n";
            return (0);
        }
    }
    else
    {
        (void)input;
        output.open(file);
        if (!output.is_open())
        {
            std::cout << flag << " file could not be opened\n";
            return (0);
        }
    }
    return (1);
}

int is_valid(int argc, char **argv, std::ifstream &input, std::ofstream &output)
{
    std::string s1;

    if (argc !=4)
    {
        std::cout << "Error: incorrect argument count\n";
        return (0);
    }
    s1 = std::string(argv[2]);
    if (s1.empty())
    {
        std::cout << "Error: empty string!\n";
        return (0);
    }
    std::string outfile_name = std::string(argv[1]) + ".replace";
    if (!open_stream(argv[1], "input", input, output))
        return (0);
    if (!open_stream(outfile_name, "output", input, output))
    {
        input.close();
        return (0);
    }

    return 1;
}


void ft_replace(std::ifstream &input, std::ofstream &output, std::string s1, std::string s2)
{
    std::string line;
    std::string new_line;
    size_t last_pos;
    size_t pos(0);

    while(std::getline(input, line))
    {   
        new_line = "";
        last_pos = 0;
        pos = line.find(s1);
        while (pos != std::string::npos)
        {
            new_line.append(line, last_pos, pos - last_pos);
            new_line.append(s2);
            last_pos = pos + s1.length();
            pos = line.find(s1, last_pos);
        }
        new_line.append(line, last_pos, line.length() - last_pos);
        output << new_line;
        if (!input.eof())
            output << '\n';
    }
}

int main(int argc, char **argv)
{
    std::ifstream input;
    std::ofstream output;
    
    if (!is_valid(argc, argv, input, output))
        return 1; 
    ft_replace(input, output, argv[2], argv[3]);
    input.close();
    output.close();

    return 0;
}
