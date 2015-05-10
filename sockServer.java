import java.io.*;
import java.net.*;

public class sockServer
{
  public static void main() 
  {
    try {
      ServerSocket serv = new ServerSocket();
      
      while(true ) {
        Socket client = serv.accept();
        
        PrintWriter pw = new PrintWriter ( Client.getOutStream(), true );
        pw.println( new java.util.Date().toString() );
        client.close();
      }
    } catch (Exception e) {
    }
  }
}
