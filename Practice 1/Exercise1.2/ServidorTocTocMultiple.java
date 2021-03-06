import java.net.*;
import java.io.*;

public class ServidorTocTocMultiple {
    public static void main(String[] args) throws IOException {

        if (args.length != 1) {
            System.err.println("Uso desde consola: ServidorTocTocMultiple <numero puerto>");
            System.exit(1);
        }

        // convertimos el numero de puerto
        int numeroPuerto = Integer.parseInt(args[0]);

        //declaramos socket que recibira peticiones
        ServerSocket serverSocket = null;
        
        //variable para usarse en un ciclo infinito
        boolean escuchando = true;
        
        try {
            serverSocket = new ServerSocket(numeroPuerto);
        } catch (IOException e) {
            System.err.println("No puedo escuchar en el puerto: numeroPuerto.");
            System.exit(-1);
        }

        while (escuchando)
            // se crea un objeto del servidor multiple de hilos , 
            //pero su ejecucion NO se hace en el hilo main de este programa
            //se hace en una copia identidca de este codigo en ejecucion (un hilo nuevo)
	    new ServidorTocTocMultipleHilos(serverSocket.accept()).start();
        }
}
