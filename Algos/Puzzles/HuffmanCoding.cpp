#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <math.h>
using namespace std;
struct TreeNode
{
    double prob;
    char symbol;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : prob(0), symbol(0), left(nullptr), right(nullptr) {}
    TreeNode(double x, char y) : prob(x), symbol(y), left(nullptr), right(nullptr) {}
    TreeNode(double x, char y, TreeNode *left, TreeNode *right) : prob(x), symbol(y), left(left), right(right) {}
};

template <typename T>
typename std::vector<T>::iterator
insert_sorted(std::vector<T> &vec, T const &item, bool (*_cmp)(TreeNode const *, TreeNode const *))
{
    return vec.insert(
        upper_bound(vec.begin(), vec.end(), item, _cmp),
        item);
}
class Huffman
{
private:
    TreeNode *htree;
    unordered_map<char, string> _symToBin;
    unordered_map<string, char> _binToSym;
    unordered_map<char, double> _symboleProbs;
    void _writeBinFile(string outputFileName, string text)
    {
        int n = text.size();
        ofstream outdata;
        outdata.open(outputFileName);
        if (!outdata)
        { // file couldn't be opened
            cerr << "Error: file could not be opened" << endl;
            exit(1);
        }
        for (auto c : text)
        {
            outdata << c;
        }
        outdata.close();
    }
    string _readFile(string filename)
    {
        fstream file;
        file.open(filename, ios::in); // open a file to perform read operation using file object
        string tp;

        if (file.is_open())
        { // checking whether the file is open
            string line;
            while (getline(file, line))
            { // read data from file object and put it into string.
                tp += line + '\n';
            }
            file.close(); // close the file object.
        }
        return tp;
    }
    void _createSymMap(TreeNode *root, string bin)
    {
        if (!root->left)
        {
            _symToBin[root->symbol] = bin;
            return;
        }
        bin.push_back('0');
        _createSymMap(root->left, bin);
        bin.pop_back();
        bin.push_back('1');
        _createSymMap(root->right, bin);
    }

public:
    Huffman() : htree(nullptr){};
    void setHTree(TreeNode *root)
    {
        htree = root;
    }
    void initializeMaps()
    {
        if (!this->htree)
        {
            throw "Please attact huffman tree";
        }
        _createSymMap(this->htree, "");
        for (auto iter : this->_symToBin)
        {
            this->_binToSym[iter.second] = iter.first;
        }
    }
    string compress(const string &messege)
    {
        string s;
        for (auto c : messege)
        {
            s += this->_symToBin[c];
        }
        return s;
    }
    string decompress(const string &messege)
    {
        int p1 = 0;
        string s;
        while (p1 < messege.size())
        {
            auto temp = this->htree;
            while (p1 < messege.size() && temp->left)
            {
                int val = (messege.at(p1) - '0');
                if (val)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->left;
                }
                p1++;
            }
            s.push_back(temp->symbol);
        }
        return s;
    }
    TreeNode *generateTree(unordered_map<char, double> symbolProbs)
    {
        auto sorter = [](TreeNode const *a, TreeNode const *b)
        {
            return a->prob > b->prob;
        };
        vector<TreeNode *> sps; // should use priority queue but stupid old me!
        for (auto iter : symbolProbs)
        {
            sps.push_back(new TreeNode(iter.second, iter.first));
        }
        sort(sps.begin(), sps.end(), sorter);
        TreeNode *root;
        while (sps.size() > 1)
        {
            auto lastNode = sps.back();
            sps.pop_back();
            auto adjacentNode = sps.back();
            sps.pop_back();
            auto left = !lastNode->symbol ? lastNode : adjacentNode;
            auto right = lastNode->symbol ? lastNode : adjacentNode;
            root = new TreeNode(lastNode->prob + adjacentNode->prob, 0, left, right);
            insert_sorted(sps, root, sorter);
        }
        return root;
    }
    unordered_map<char, double> generateSymbolProbs(const string &text)
    {
        unordered_map<char, double> map;
        for (auto c : text)
        {
            if (map.count(c))
            {
                map[c] += 1;
            }
            else
            {
                map[c] = 1;
            }
        }
        return map;
    }
    void compressFile(string baseFileName)
    {
        string outputFileName = baseFileName + "_enc.txt";
        string inputFileName = baseFileName + ".txt";
        string contents = this->_readFile(inputFileName);
        string cc = this->compress(contents);
        this->_writeBinFile(outputFileName, cc);
        cout << cc;
    }
    void decompressFile(string baseFileName)
    {
        string outputFileName = baseFileName + "_dec.txt";
        string inputFileName = baseFileName + ".txt";
        string contents = this->_readFile(inputFileName);
        string dc = this->decompress(contents);
        this->_writeBinFile(outputFileName, dc);
        cout << dc;
    }
    unordered_map<char, double> getDefaultProbs()
    {
        unordered_map<char, double> umap;
        umap['E'] = 12.0;
        umap['e'] = 12.0;
        umap['T'] = 9.1;
        umap['t'] = 9.1;
        umap['A'] = 8.12;
        umap['a'] = 8.12;
        umap['O'] = 7.68;
        umap['o'] = 7.68;
        umap['I'] = 7.31;
        umap['i'] = 7.31;
        umap['N'] = 6.95;
        umap['n'] = 6.95;
        umap['S'] = 6.28;
        umap['s'] = 6.28;
        umap['R'] = 6.02;
        umap['r'] = 6.02;
        umap['H'] = 5.92;
        umap['h'] = 5.92;
        umap['D'] = 4.32;
        umap['d'] = 4.32;
        umap['L'] = 3.98;
        umap['l'] = 3.98;
        umap['U'] = 2.88;
        umap['u'] = 2.88;
        umap['C'] = 2.71;
        umap['c'] = 2.71;
        umap['M'] = 2.61;
        umap['m'] = 2.61;
        umap['F'] = 2.3;
        umap['f'] = 2.3;
        umap['Y'] = 2.11;
        umap['y'] = 2.11;
        umap['W'] = 2.09;
        umap['w'] = 2.09;
        umap['G'] = 2.03;
        umap['g'] = 2.03;
        umap['P'] = 1.82;
        umap['p'] = 1.82;
        umap['B'] = 1.49;
        umap['b'] = 1.49;
        umap['V'] = 1.11;
        umap['v'] = 1.11;
        umap['K'] = 0.69;
        umap['k'] = 0.69;
        umap['X'] = 0.17;
        umap['x'] = 0.17;
        umap['Q'] = 0.11;
        umap['q'] = 0.11;
        umap['J'] = 0.1;
        umap['j'] = 0.1;
        umap['Z'] = 0.07;
        umap['z'] = 0.07;
        for (int i = 0; i < 127; i++)
        {
            if ((i < 'A' || i > 'Z') && (i < 'a' || i > 'z'))
            {

                umap[i] = 0.1;
            }
        }
        // softmax
        double max = 12.0;
        double sum=0;
        for (auto iter:umap)
        {
            sum += expf(iter.second-max);
        }
        double scale = max + log(sum);
        for (auto iter:umap)
        {
            umap[iter.first] = expf(iter.second-scale);
        }
        

        // to-do: add from wiki
        return umap;
    }
    void initDefaults()
    {
        auto umap = this->getDefaultProbs();
        this->_symboleProbs = umap;
        auto tree = this->generateTree(umap);
        this->setHTree(tree);
        this->initializeMaps();
    }
    double getEntropy()
    {
        double entropy = 0;
        for (auto iter : this->_symboleProbs)
        {
            entropy += -1 * iter.second * (log2(iter.second));
        }
        return entropy;
    }
    double getAvgL()
    {
        double  L;
        for (auto iter : this->_symboleProbs)
        {
            L += (this->_symToBin[iter.first].size() * iter.second);
        }
        return L;
    }
};
int main()
{
    Huffman hf;
    hf.initDefaults();
    string input = "shubham";
    cout << hf.getEntropy() << "\n" << hf.getAvgL() << endl;
    return 0;
}
// 01110011011010000111010101100010011010000110000101101101 <- "shubham" in binary
// 100110101101001001000010101111101001011 <- "shubham" using this huffman code 