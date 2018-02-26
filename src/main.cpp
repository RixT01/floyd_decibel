#include <cstdio>
#include "floyd.hpp"
#include <string>
#include <vector>


using namespace std;

bool found_pswwd;

int main(int argc, char* argv[]) {
    string buf;
    getline(cin, buf);

    int cases_num = stoi(buf);

    vector<vector<double>> result_matrix(cases_num);

    for (unsigned int c = 0; c < cases_num; c++){

        getline(cin, buf);
        unsigned short pos = buf.find(" ");

        unsigned int nodes = stoi(buf.substr(0, pos));
        buf.erase(0, pos + 1);

        pos = buf.find(" ");

        unsigned int edges = stoi(buf.substr(0, pos));
        buf.erase(0, pos + 1);

        unsigned int queries = stoi(buf);

        // cout << "nodes: {" << nodes << "}" << endl;
        // cout << "edges: {" << edges << "}" << endl;
        // cout << "queries: {" << queries << "}" << endl;



        double** my_matrix = createMatrix(nodes);

        //construyendo matriz
        for(unsigned int e = 0; e < edges; e++){
            getline(cin, buf);
            unsigned short pos2 = buf.find(" ");

            unsigned int node1 = stoi(buf.substr(0, pos2)) - 1;
            buf.erase(0, pos2 + 1);

            pos2 = buf.find(" ");

            unsigned int node2 = stoi(buf.substr(0, pos2)) - 1;
            buf.erase(0, pos2 + 1);

            unsigned int weight = stoi(buf);

            // cout << "node1: {" << node1 << "}" << endl;
            // cout << "node2: {" << node2 << "}" << endl;
            // cout << "weigth: {" << weight << "}" << endl;
            
            my_matrix[node1][node2] = weight;
            my_matrix[node2][node1] = weight;

            //cout << "I made it here" << endl;
            //printMatrix(my_matrix, nodes);
        }


        // CHECKPOINT
        floyd_algorithm(my_matrix, nodes);

        
        //efectuando queries
        for(unsigned int q = 0; q < queries; q++){
            getline(cin, buf);
            unsigned short pos3 = buf.find(" ");

            unsigned int ini_query = stoi(buf.substr(0, pos3)) - 1;
            buf.erase(0, pos3 + 1);

            unsigned int end_query = stoi(buf) - 1;
            //cout << "ini_query: {" << ini_query << "}" << endl;
            //cout << "end_query: {" << end_query << "}" << endl;
            
            double response = my_matrix[ini_query][end_query];

            result_matrix[c].push_back(response);

        }



        
    }

    for(unsigned int c = 0; c < cases_num; c++){
        cout << "Case " << c+1 << ":" << endl;

        unsigned int array_size = result_matrix[c].size();

        //cout << "Size of my sub_array: " << array_size << endl;

        for(unsigned int q = 0; q < array_size; q++){
            if(isinf(result_matrix[c][q])){
                cout << "no path" << endl;
            }
            else{
                cout << result_matrix[c][q] << endl;
            }
            
        }

    }
    
}

