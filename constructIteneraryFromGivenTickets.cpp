/*
Given an bunch of airline tickets with [from, to], for example [MUC, LHR], [CDG, MUC], [SFO, SJC], [LHR, SFO], please reconstruct the itinerary in order, 
for example: [ CDG, MUC, LHR, SFO, SJC ]. 
//tickets can be represented as nodes
*/
public List<String> reconstruct(String [][] itinerary){
		HashMap <String,String> graph = new HashMap<> ();
		HashSet <String> relation = new HashSet<> ();
		for (String [] it : itinerary) {
			graph.put(it[0], it[1]) ;
		    relation.add(it[1]) ;
		}
		
		String start = "" ;
		for (String [] it : itinerary) {
			if (!relation.contains(it[0])) {
				start = it[0] ;
			}
		}		
 		if ("".equals(start)) {
 			return new ArrayList<String> ();
 		}
 		List<String> rst = new ArrayList<> ();
 		rst.add(start) ;
 		while (graph.containsKey(start)) {
 			start = graph.get(start) ;
 			rst.add(start) ;
 		}		
		return rst ;
	}
