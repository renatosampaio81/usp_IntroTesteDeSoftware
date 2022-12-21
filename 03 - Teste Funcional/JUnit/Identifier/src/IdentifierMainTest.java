 /*
 * Inserindo e Utilizando JUnit no seu projeto
 * 01 - Botão direito no nome do projeto -> Build Path -> Add Libraries..
 * 02 - Botão direito na classe a ser testada -> New -> JUnit Test Case
 * 03 - (para rodar os testes) Botão direito na classe teste -> run as.. -> JUnit test
 * 
 */

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class IdentifierMainTest {

	static private ByteArrayOutputStream boOut; /*objeto que irá capturar a string retornada pelo IdentifierMain.java*/
	static private PrintStream psOut; /*objeto que captura o conteúdo que será exibido no console do teste*/

	/*@BeforeClass*/
	@BeforeAll
	public static void beforeClassInit() {
		boOut = new ByteArrayOutputStream(); 
		psOut = new PrintStream(boOut);
		System.setOut(psOut);
	}
	
	/*@AfterClass*/
	@AfterAll
	public static void afterClassFinalize() {
		psOut.close();
	}
	
	/*@Before*/
	@BeforeEach
	public void setUp() {
		boOut.reset(); /*limpar o conteúdo do objeto a cada nova execućão do caso de teste*/
	}
	
	@Test
	public void testeValido01() {
		IdentifierMain.main(new String [] {"a1"});
		String output = boOut.toString();
		
		assertEquals("Valido", output);
	}
	
	@Test
	public void testeInvalido02() {
		IdentifierMain.main(new String [] {"2b3"});
		String output = boOut.toString();
		
		assertEquals("Invalido", output);
	}
	
	@Test
	public void testeInvalido03() {
		IdentifierMain.main(new String [] {"z-12"});
		String output = boOut.toString();
		
		assertEquals("Invalido", output);
	}
	
	@Test
	public void testeInvalido04() {
		IdentifierMain.main(new String [] {"a1b2c3d"});
		String output = boOut.toString();
		
		assertEquals("Invalido", output);
	}
}
