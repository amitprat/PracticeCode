/*
Tags - 
  Create workgroup from given connection among employees.
  Create hierarchy chart in an organization showing connectedness.
  Find the team from given connection among emplyees
  Create iternary from given set of tickets
    Other solution is also used for this specific question -
      for each iternary pair, create hash table with like map[destination] = source
      for each pair, check if source is not present in hash table
        if found, then this is source of journey 
        break;
      first = this pair 
      print first
      while( (other = map.find(first.second)) != map.end() )  
        print other
        first = other
*/
/*

You are given an array of n elements. The elements have are n-bit long too. 

Now n here represents the number of employees in a company. Element with index 0 is information about employee 0, at index 1 is information of employee 1.... 

For each element, the bits represent whether that employee works (not same team... just works) with employee at that index. 
Ex. element 0 = 0110 => emplyee 0 works with employee 1 and 2 
element 1 = 1001 => emplyee 1 works with employee 0 and 3 
... 

Put employees in groups in which they work. The transitive property is applicable here i.e. if A works with B and B works with C, ABC will be in one group. 

The solution needs to efficient in terms of run time and memory. I hope the above is clear.

- Anon123 about a year ag

Union-Find Set might work. 
(1)at first everybody himself/herself forms a set. 
(2)scan every element's bits, if the kth bit of element[i] is 1, which means i work with k, then find k's set and i's set, and merge them if they are not in the same sets. 
(3)as the average time complexity of find and merge is O(1), the total time complexity is O(N*N), while space complexity is O(N)

- uuuouou about a year ago | Flag Reply
0
of 0 votes

class Program
    {
        static void Main(string[] args)
        {
            String[] inputArray = { "0110000", "1010000", "1100000", "0000001", "0001000", "0000100", "0000010" /*"0110000", "1010000", "1100000", "0000100", "1000001", "0001000", "0000010"*/ };
            IdentifyGroups.FindGroups(inputArray);
        }
    }

    public class IdentifyGroups
    {
        private static int[] groups;		// groupNumber of the node(employee)
        private static Dictionary<int, List<EmployeeGroup>> employeeGroups = new Dictionary<int, List<EmployeeGroup>>();

        public static void FindGroups(String[] employeeInformation)
        {
            int totalEmployees = employeeInformation.Length;
            groups = new int[totalEmployees];

            for (int i = 0; i < totalEmployees; i++)
            {
                groups[i] = i;
                employeeGroups[i] = new List<EmployeeGroup>(new[] { new EmployeeGroup { Id = i, Employee = employeeInformation[i] } });
            }

            // Mapping each employee to its group
            for (int i = 0; i < totalEmployees; i++)
            {
                int currentEmployeeGroup = groups[i];
                char[] empId = employeeInformation[i].ToCharArray();
                for (int j = 0; j < empId.Length; j++)
                {
                    if (empId[j] == '1')
                    {
                        int relatedGroupKey = groups[j];
                        if (relatedGroupKey != currentEmployeeGroup)
                        {
                            employeeGroups[currentEmployeeGroup].AddRange(employeeGroups[relatedGroupKey]);
                            foreach (EmployeeGroup group in employeeGroups[relatedGroupKey])
                            {
                                groups[group.Id] = currentEmployeeGroup;
                            }

                            employeeGroups.Remove(relatedGroupKey);
                        }
                    }
                }
            }

            //Printing the group
            foreach (KeyValuePair<int, List<EmployeeGroup>> m in employeeGroups)
            {
                Console.Write(m.Key + " : ");
                foreach (EmployeeGroup value in m.Value)
                {
                    Console.Write(value.Employee + ", ");
                }

                Console.WriteLine();
            }
        }
    }

    public class EmployeeGroup
    {
        public int Id;
        public string Employee;
    }

*/
/*Solution by Me */
#include    <iostream>
#include    <vector>
#include    <unordered_map>
using namespace std;

class UnionFindByRank
{
    int v;
    int *index;
    int *rank;
    public:
    UnionFindByRank(int v) : v(v) {
        index = new int[v];
        rank = new int[v];
        for(int i=0;i<v;i++)
            index[i] = i, rank[i] = 0;
    }
    void union1(int i,int j) {
        int pid = find(i);
        int qid = find(j);

        if(rank[pid] < rank[qid])
            index[pid] = qid;
        else if(rank[pid] > rank[qid])
            index[qid] = pid;
        else {
            index[qid] = pid;
            rank[qid]++;
        }
    }
    int find(int i) {
        while( i != index[i] )
            i = index[i];
        return i;
    }
    bool connected(int i,int j) {
        return (find(i) == find(j));
    }
};
int main()
{
    string arr[] = { "0110000", "1010000", "1100000", "0000001", "0001000", "0000100", "0000010" };
    int n = sizeof(arr)/sizeof(arr[0]);
    UnionFindByRank obj(n);
    for(int i=0;i<n;i++) {
        string s1 = arr[i];
        int len = s1.length();
        for(int k=0;k<len;k++) {
            if ( s1[k] == '1' ) {
                obj.union1(i,k);
            }
        }
    }
    unordered_map<int, vector<int> > sets;
    for(int i=0;i<n;i++) {
        int root = obj.find(i);
        vector<int> v;
        if(sets.find(root) != sets.end()) {
            v = sets[root];
        }
        v.push_back(i);
        sets[root] = v;
    }

    for( auto i : sets ) {
    	cout<<i.first<< " : ";
        for(int j=0;j<i.second.size();j++) {
            cout<<i.second[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
  Op:
  5 : 3 4 5 6 
  0 : 0 1 2 
*/
/*Second Method - 

* Create graph - for each '1' create edge between two vertices
* now the graph will contain forest of connected graphs 
* do the dfs from every node and print the nodes in a connected graph
*/
