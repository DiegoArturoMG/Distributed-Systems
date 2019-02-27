public class Cadenota {
    private String cadenota;
    public Cadenota(){
        cadenota = "";
    }
    public static void main(String[] args) {
        Cadenota hola = new Cadenota();
        hola.generateString();
    }

	public char randomLetra(){
		return (char) ('A'+(Math.random()*26));
	}


	public String randomPalabra(){
		String s = "";
		for(int i=0;i<3;i++){
			s += randomLetra();
		}
		return s;
	}

	public void imprimirCadenota(String cadena){
		System.out.println("Cadena: \n");
		System.out.println(cadena);
	}

	public void imprimirCadenotaC(String cadena){
		for(int i=0;i<cadena.length();i+=4){
			System.out.println(cadena.charAt(i) + cadena.charAt(i+1) + cadena.charAt(i+2) + cadena.charAt(i+3));
		}
	}

	void generateString(){
		int n = 10;
		int caractTot = 3;
		int totCaractAlph = (int) Math.pow(26,caractTot);

		for(int i=0;i<n*totCaractAlph;i++){
			cadenota+=randomPalabra();
			cadenota+=" ";
		}

		imprimirCadenota(cadenota);

		int conteo = 0;
		int pos;

	         while (cadenota.indexOf("IPN") > -1) {
	            cadenota = cadenota.substring(cadenota.indexOf("IPN") + "IPN".length(), cadenota.length());
	            conteo++;
	       }

	/*
		for(int i=0;i<cadenota.length();){
			pos = cadenota.contains("IPN");
			if(pos != cadenota.){
				conteo++;
				i = pos + 4;
				continue;
			}
			break;
		}*/

		System.out.println("Se encontraron: " + conteo + " ocurrencias");
	}
}