#include "Task5.h"

using namespace std;

void Task5::input()
{
	//Opening file in read mode.
    std::string inputFile;
    std::cout << "Enter file name for Task5: ";
    std::cin >> inputFile;
    ifstream infile (inputFile);
    if (infile)
    {
        std::string line;  
        while ( getline (infile,line) )
        {
	    if(line.length()==0)
	    {
		    break;
	    }
            inputLines.push_back(line);
        }
        infile.close(); //Closing file.
    }
    else cout << "Unable to open file"; 

}

void Task5::process()
{
	std::vector<Edge> edges; //EdgeList
    std::vector<std::string> labels; // Stores vertices names.

    std::vector<int> rmIndices; //Stores the indices which are in least degree 50% 
    std::vector<double> degree; //Stores Degree of each vertex
    std::vector<Degree> arr;    
    std::vector<int> prevIndex; //Used to print indices of output graph.
	
    //Extracting no.of vertices and their names in graph.
	std::string size="";
    std::string currline=inputLines[2];
    int ind=0;
    while(currline[ind] != '=')
    {
        ind++;
    }
    ind++;
    while(currline[ind] != '\0')
    {
        size+=currline[ind];
        ind++; 
    }  
    n = stoi(size);
    //std::cout << n << endl;

    string str = "";
    int i=0;
    while(inputLines[4][i]!='\0')
    {
        if(inputLines[4][i]==',')
        {
            labels.push_back(str);
            i=i+2;
            str="";
            continue;
        }
        str+=inputLines[4][i++];
    }
    labels.push_back(str);

    //Extracting information of graph (i.e edges and their weights).
    for(int i=6;i<inputLines.size();i++)
    {
       std::string curr = inputLines[i];
       int index = 0;
       vector<int> nodes;
       int u,v;
       double w;

       string str="";
       while (curr[index]!='\0')
        {
            if(curr[index]==' '){
               nodes.push_back(stoi(str));
               index++;
               str="";
               continue;
            }
            str+=curr[index++];
        }
        //Creating Edgelist.
        w = stod(str);
        u = (nodes[0]);
        v= (nodes[1]);
        Edge e1(u, v, w);
        edges.push_back(e1);
    }

    

    for(int j=0;j<n;j++)
    {
        degree.push_back(0);//Initializing degree of each vertex to 0.
    }
    for(int j=0;j<edges.size();j++) //Calculating degree of each vertex.
    {
        int u = edges.at(j).getStartVertex();
        int v = edges.at(j).getEndVertex();
        double w = edges.at(j).getWeight();
        degree[u-1]=degree[u-1]+w;
        degree[v-1]=degree[v-1]+w;
    }

    for(int j=0;j<degree.size();j++)
    {
        Degree d1(j+1, degree[j]);
        arr.push_back(d1);
    }
    Sort s(arr); //Sorting array according to their degree.
    std::vector<Degree> Sortedarr = s.Sorting();
    

    for(int j=0;j<(n/2);j++)
    {
        rmIndices.push_back(Sortedarr[j].getPrevIndex());
    }

    std::string out_vertices=""; // Contains labels of remaining vertices with space seperated.
    //Removing names of removed vertices to write them to output file.
    
    for(int j=n-1;j>=(n/2);j--) //Storing indices of given graph (only which are in output graph) in decreasing order of degree
    {
        int ni = Sortedarr[j].getPrevIndex();
        prevIndex.push_back(ni);
    }

    for(int j=0;j<prevIndex.size();j++) //Storing labels of output vertices in out_vertices list.
    {
        int index=prevIndex.at(j);
        out_vertices = out_vertices + labels[index-1];
        if(j!=(n/2))
        {
            out_vertices = out_vertices + "," + " ";
        }
    }
    outputLines.push_back(out_vertices);
    
    for(int j=0;j<edges.size();j++)
    {
        int check=0; // If any end point of edge is in removed vertices check is made '1'. 
        int u = edges.at(j).getStartVertex();
        int v = edges.at(j).getEndVertex();
        double w = edges.at(j).getWeight();
        for(int k=0;k<rmIndices.size();k++)
        {
            if(rmIndices.at(k)==u || rmIndices.at(k)==v)
            {
                check=1;
            }
        }
        //If check=0, this means that edge won't contain deleted vertex, so we store that edge for printing.
        if(check==0)
        {
            int su,sv;
            for(int p=0;p<prevIndex.size();p++)
            {
                if(prevIndex.at(p)==u)
                {
                    su=p+1;
                }
                if(prevIndex.at(p)==v)
                {
                    sv=p+1;
                }
            }
            std::string str_out=to_string(su)+" "+to_string(sv)+" "+to_string(w);
            outputLines.push_back(str_out);
        }
    }	
}



void Task5::output()
{
	//Opening File in write mode. 
    ofstream outfile ("Task5_output.dl");
    if(outfile.is_open())
    {
        int N = n-(n/2);
        outfile << "DL\n";
        outfile << "format=edgelist1\n";
        outfile << "n=";
        outfile << N;
        outfile << "\n";
        outfile << "labels:\n";
        outfile << outputLines[0];
        outfile << "\n";
        outfile << "data:\n";
        for(int j=1;j<outputLines.size();j++)
        {
            outfile << outputLines[j];
            outfile << "\n";
        }
        outfile.close();//Closing file.
    }    
    else
    {
        cout << "Unable to open file";
    }
}
