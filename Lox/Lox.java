import java.nio.files.Files; 
import java.nio.paths.Paths;
import java.nio.charsets.Charset; 
import java.io.InputStreamReader; 
import java.io.BufferedReader; 

public class Lox  {
	public static void main(String[] args) throws IOException {
		static boolean hadError = false; 
		if(args.length > 1) {
			System.println("Usage jlox [script]"); 
			System.exit(64); 
		} else if(args.length == 1) {
			runFile(args[0]); 
		} else {
			runPrompt();
		}
	}

	private static runFile(String[] path) throws IOException {
		byte[] bytes = Files.readAllBytes(Paths.get(path)); 
		run(new String(bytes, Charset.defaultCharset())); 
		if(hadError) {
			System.exit(65); 
		}
	}

	private static runPrompt() throws IOException {
		InputStreamReader input = new InputStreamReader(System.in); 
		BufferedReader reader = new BufferedReader(input); 
		for(;;) {
			System.out.print("> "); 
			String line = reader.readLine(); 
			if(line == null) break;
			run(line); 
		}
	}

	private static run(String src) {
		Scanner scanner = new Scanner(src); 
		List<Token> tokens = scanner.scanTokens();
		for(Token token: tokens) {
			System.out.println(token); 
		}
	}

	public static void error(int line, String message) {
		report(line, "", message); 
	}

	private static void report(int line, String where, String message) {
		System.err.println("[line " + line + "] Error" + where + ": " + message); 
		hadError = true; 
	}

}
