/*
0 2 5 1 -1
2 0 8 7  9
5 8 0 -1 4
1 7 -1 0 2
-1 9 4 2 0
*/

#include <stdio.h>

#define MAX_NODECOUNT 100
#define Color_Red "\x1b[31;1m;" // Color Start
#define Color_Blue "\x1b[34;1m;" // Color Start
#define Color_end "\x1b[39;49m" // To flush out prev settings

#define LOG_RED(X) printf("%s %s %s",Color_Red,X,Color_end)
#define LOG_BLUE(X) printf("%s %c %s",Color_Blue,X,Color_end)


struct dnode
{
   int index;
   int weight_cumulative;
   struct dnode * left;
   struct dnode * right;
};

struct node
{
    int node_index;
    int topology[MAX_NODECOUNT][MAX_NODECOUNT];
    int maxseq[MAX_NODECOUNT];
    struct dnode root;
};
struct node all_nodes[MAX_NODECOUNT];
int original_topology[MAX_NODECOUNT][MAX_NODECOUNT];

int nodeCount;

void updateLSP(int srcindex, int destindex, int * LSPArray, int seqNumber)
{
   //get the srcindex node

   //get the destindex node

   //Check the seqid of dest to check if this message has already been received at the dest from this 	//source

   //update the destindex nodes topology matrix with the the LSPArray

   //Send the LSPArray to all neighbours other than the one it came from

   //
}

void loadOriginalTopology()
{
   //read the network.txt to form a matrix

   //Initialize the nodecount variable
   int n, m, count = 5;
  
  FILE *inp; 
  inp = fopen("network.txt","r");
  for (n = 0; n < count; ++n) {
  for (m = 0; m < count; ++m)
    fscanf (inp, "%d", &original_topology[n][m]);
  }
  fclose (inp); 
  
  for (n = 0; n < count; ++n) 
  {
    for (m = 0; m < count; ++m)
    {
      printf("%d  ",original_topology[n][m]);
    }
     printf("\n");
  }
   }

void InitializeNodes()
{
   //Initialize nodecount number of nodes

   //Load the topology
   loadOriginalTopology();

  //Update the initialized nodes from the original_topology matrix

  //for each node in the n/w, create and send LSP packages with apt seq numbers
}

void GenerateRoutingTable(int index)
{
   //Get the node at index

   //Initialize the root of shortest path tree 

   //Dijkstras algorithm to generate the shortest path tree

   //Generate the routing table for the node. Use DFS to traverse the tree


}

void PrintShortestPath(int src, int dst)
{
   //Get the node at index src

   //Get the node at index dst

   //Check if the routing table has been generated, if not generate it

   //use dfs to  traverse the tree and print the path to the dst node
}


int main()
{
   //Program prompts in blue. User input in red.
   char input_buffer[30];

  //Display the Menu screen
   char menu_input = 'a';
  while(menu_input!='4')
  {
     LOG_RED("\n\n\n\t 1-Load File\n\t 2-Build Routing Table for each Router \n\t 3-Out Optimal Path and Minimum Cost\n\t 4-Exit Program\n\n ");
     scanf(" %c",&menu_input);
     

      switch(menu_input)
      {
	case '1' :
	  InitializeNodes();
	  break;
	case '2' :
	  break;
	case '3' :
	  break;
	case '4' :
	  return(0);
	default :  printf("Wrong menu key entered. Try again : ",menu_input);
      }

    fflush(stdin);
    
  }
}


/*
1) Test if all the nodes are getting loaded up with the same values as the same in network.txt
2) Test if path generated is same as expected for a given graph
3) Test correct path generated for geven two nodes

*/





