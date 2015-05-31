/*
Give a path get it's canonical form. So for example if you have path in the form e/../../a/d/./../b/c then you should return a/b/c. 

I have the solution but it's not the most optimal or the best solution. I just wanted to see what others have.
*/
public static String getCanonicalPath(String input){
		if(input==null||input.trim().length()==0){
			return null;
		}
		
		String[] path = input.split("/");
		Stack<String> canonicalForm = new Stack<String>();
		StringBuilder sb = new StringBuilder();
		for(String token:path){
			if(token.equals("..")){
			if(!(canonicalForm.isEmpty())&&canonicalForm.peek()!=".."){
				sb.append(canonicalForm.pop()+"/");
			}
			}else if(token.equals(".")){
				System.out.println("Skipping .");
			}else{
				canonicalForm.push(token);
			}
		}
		
		for(String token:canonicalForm){
			sb.append(token+"/");
		}
		return sb.toString();
		
	}
