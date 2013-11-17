/*
0 2 5 1 -1
2 0 8 7  9
5 8 0 -1 4
1 7 -1 0 2
-1 9 4 2 0
*/

#include <stdio.h>

#define MAX_NODECOUNT 100
#define Color_Red "\x1b[31;1m" // Color Start
#define Color_Blue "\x1b[34;1m" // Color Start
#define Color_end "\x1b[39;49m" // To flush out prev settings

#define LOG_RED(X) printf("%s %s %s",Color_Red,X,Color_end)
#define LOG_BLUE(X) printf("%s %c %s",Color_Blue,X,Color_end)

//#define DEBUG_INI 0;
#define DEBUG 0;

#ifdef DEBUG_INI
# define DEBUG_PRINT_INI(x) printf x
#else
# define DEBUG_PRINT_INI(x) do {} while (0)
#endif

#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

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
    int max_seq_recvd[MAX_NODECOUNT];
    struct dnode root;
};
struct node all_nodes[MAX_NODECOUNT];
int original_topology[MAX_NODECOUNT][MAX_NODECOUNT];

int nodeCount= 5;
   //Todo remove harcoding;

void updateLSP(int senderIndex, int srcindex, int destindex, int * LSPArray, int seqNumber)
{
  DEBUG_PRINT_INI(("\nSending LSPArray from src %d through sender %d to dest %d",srcindex,senderIndex,destindex));
  
  
  //get the destindex node
  struct node * dst_node = &all_nodes[destindex];
  
  //Check the seqid of dest to check if this message has already been received at the dest from this 	//source
  if(dst_node->max_seq_recvd[srcindex] >= seqNumber)
    return;

  dst_node->max_seq_recvd[srcindex] = seqNumber;
  
  //update the destindex nodes topology matrix with the the LSPArray
  int neighbour_index=0;
  for(;neighbour_index<nodeCount;neighbour_index++)
  {
      dst_node->topology[srcindex][neighbour_index] = LSPArray[neighbour_index];
  }

  //Send the LSPArray to all neighbours other than the one it came from
  neighbour_index=0;
  for(;neighbour_index<nodeCount;neighbour_index++)
  {
    
    //Check if a neighbour exists
    if(dst_node->topology[destindex][neighbour_index] > 0)
    {
      if(neighbour_index != srcindex && neighbour_index != senderIndex)
	updateLSP(destindex, srcindex,neighbour_index,LSPArray,1); 
    }
  }
   //
}

void loadOriginalTopology()
{
   //read the network.txt to form a matrix

   //Initialize the nodecount variable
   int n, m;
  
  FILE *inp; 
  inp = fopen("network.txt","r");
  for (n = 0; n < nodeCount; ++n) {
  for (m = 0; m < nodeCount; ++m)
    fscanf (inp, "%d", &original_topology[n][m]);
  }
  fclose (inp); 
  
  
}

void DebugPrintOriginalTopology()
{
  int n,m;
  printf("Original Topology \n");
  for (n = 0; n < nodeCount; ++n) 
  {
    
    for (m = 0; m < nodeCount; ++m)
    {
      printf("%d  ",original_topology[n][m]);
    }
     printf("\n");
  }
  
}

void DebugPrintAllNodeToppology()
{
  int n,m;
  for (n = 0; n < nodeCount; ++n) 
  {
    struct node * current_node = &all_nodes[n];
    printf("\n\nTopology for Currentnode Index :%d\n",current_node->node_index);
    
    int k;
    for (k = 0; k < nodeCount; ++k) 
    {
      for (m = 0; m < nodeCount; ++m)
      {
	printf("%d  ",current_node->topology[k][m]);
      }
      printf("\n");
    }
     
  }
}

void InitializeNodes()
{
   //Load the topology
   loadOriginalTopology();

   //Initialize node.topology from the original_topology matrix
   //So that each node only konws its own topology
   int node_index=0;
   struct node * current_node;
   for(;node_index<nodeCount;node_index++)
   {
     //Get the node to be initialized
     current_node =&all_nodes[node_index];
     
     //Initialize the nodeindex
     
      
     current_node->node_index = node_index;
     DEBUG_PRINT_INI(("Current node initialized : %d \n",current_node->node_index));
     int neighbour_index=0;
     for(;neighbour_index<nodeCount;neighbour_index++)
     {
       current_node->topology[node_index][neighbour_index] = original_topology[node_index][neighbour_index];
       DEBUG_PRINT_INI((" %d ",  current_node->topology[node_index][neighbour_index]));
     }
     DEBUG_PRINT_INI(("\n"));
   }
   
  //for each node in the n/w, create and send LSP packages with apt seq numbers
  //Create LSP packet
  DEBUG_PRINT_INI(("Current node initialized : %d \n",all_nodes[2].node_index));
  
  node_index=0;
  for(;node_index<nodeCount;node_index++)
  {
    //Get the node to be initialized
    current_node =&all_nodes[node_index];
    DEBUG_PRINT_INI(("Currentnode.node_index : %d node_index : %d \n",current_node->node_index,node_index));

    //Send LSP packet to neighbours
    int neighbour_index=0;
    for(;neighbour_index<nodeCount;neighbour_index++)
    {
      //Check if a neighbour exists
      if(current_node->topology[node_index][neighbour_index] > 0)
      {
	int src = current_node->node_index;
	int dst = neighbour_index;
	int * LSPArray = current_node->topology[src];
	updateLSP(src,src,dst,LSPArray,1); 
      }
    }
  } 
  DebugPrintAllNodeToppology();
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





