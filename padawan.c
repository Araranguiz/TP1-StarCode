#include <stdio.h>

const float CONST_MIDICLORIANOS = 0.0F;
const char CONST_VOLUNTAD = 'v';
const char CONST_PASADO = 'p';
const float CONST_PROBABILIDAD = 0.0F;

const float MIDICLORIANOS_MIN = 100.0F;
const float MIDICLORIANOS_MAX = 2999.9F;

const float CONST_INFLUENCIA = 3.4F;
const float CONST_OSCURIDAD = 0.001117684315F;

#define V_FLOJA 'f'
#define V_BUENA 'b'
#define V_MEDIANA 'm'
#define V_ALTA 'a'
#define V_ENORME 'e'
#define V_PELIGROSA 'p'

const float VOLUNTAD_F_B = 10.3F;
const float VOLUNTAD_M_A = 54.5F;
const float VOLUNTAD_E_P = 103.4F;

#define P_BUENO 'b'
#define P_NORMAL 'n'
#define P_TRAGICO 't'

const float PASADO_N_T = 0.4F;
const float PASADO_B = 1.5F;


float recibir_midiclorianos(){

	float midiclorianos = CONST_MIDICLORIANOS;

		do
		{
			printf("\nIngrese la cantidad de midiclorianos que posea en un rango de 100.0 a 2999.9:\n");
			scanf("%f", &midiclorianos);

			if( (midiclorianos < MIDICLORIANOS_MIN) || (midiclorianos > MIDICLORIANOS_MAX) ){
					printf("INGRESO NO VALIDO!\n");
			}else{
					printf("Cantidad de midiclorianos aceptados!\n");
			}

		} while( (midiclorianos < MIDICLORIANOS_MIN) || (midiclorianos > MIDICLORIANOS_MAX) );

	return midiclorianos;
}

char recibir_voluntad(){

	char voluntad = CONST_VOLUNTAD;

		do
			{
				printf("\nIngrese su nivel de voluntad:\nFloja [f] - Buena [b] - Mediana [m] - Alta [a] - Enorme [e] - Peligrosa [p]\n");
				scanf(" %c", &voluntad);

			if( (voluntad == V_FLOJA) || (voluntad == V_BUENA) || (voluntad == V_MEDIANA) || (voluntad == V_ALTA) || (voluntad == V_ENORME) || (voluntad == V_PELIGROSA) )
			{
				printf("Nivel de voluntad aceptado!\n");
			}else{
				printf("INGRESO NO VALIDO!\n");
			}

		} while ( (voluntad != V_FLOJA) && (voluntad != V_BUENA) && (voluntad != V_MEDIANA) && (voluntad != V_ALTA) && (voluntad != V_ENORME) && (voluntad != V_PELIGROSA) );

	return voluntad;
}
	

void definir_voluntad(char voluntad){

	float d_voluntad = CONST_VOLUNTAD;

	switch(voluntad){
		case V_FLOJA:
			d_voluntad = VOLUNTAD_F_B;
			break;
		case V_BUENA:
			d_voluntad = VOLUNTAD_F_B;
			break;
		case V_MEDIANA:
			d_voluntad = VOLUNTAD_M_A;
			break;
		case V_ALTA:
			d_voluntad = VOLUNTAD_M_A;
			break;
		case V_ENORME:
			d_voluntad = VOLUNTAD_E_P;
			break;
		default:
			d_voluntad = VOLUNTAD_E_P;
	}
	printf("\nVOLUNTAD: %f\n", d_voluntad);
}


char recibir_pasado(){

	char pasado = CONST_PASADO;

		do
			{
				printf("\nIngrese su tipo de pasado:\nBueno [b] - Normal [n] - Tragico [t]\n");
				scanf(" %c", &pasado);

			if( (pasado == P_BUENO) || (pasado == P_NORMAL) || (pasado == P_TRAGICO) )
			{
				printf("Tipo de pasado aceptado!\n");
			}else{
				printf("INGRESO NO VALIDO!\n");
			}

		} while ( (pasado != P_BUENO) && (pasado != P_NORMAL) && (pasado != P_TRAGICO) );

	return pasado;

}

void definir_pasado(char pasado){

	float d_pasado = CONST_PASADO;

	switch(pasado){
		case P_BUENO:
			d_pasado = PASADO_B;
			break;
		default:
			d_pasado = PASADO_N_T;
	}
	printf("\nPASADO: %f\n", d_pasado);
}



float calculo_influencia(float midiclorianos){

	float influencia = CONST_MIDICLORIANOS;
	float constante_influencia = CONST_INFLUENCIA;

	return influencia = midiclorianos * constante_influencia;;
}


float calculo_sith (float voluntad, float influencia, float pasado){

	float constante_oscuridad = CONST_OSCURIDAD;
	float const_probabilidad = CONST_PROBABILIDAD;
	
	return const_probabilidad = voluntad + (constante_oscuridad * influencia) / pasado;


}

int main(){

	float midiclorianos = CONST_MIDICLORIANOS;
	char voluntad = CONST_VOLUNTAD;
	char pasado = CONST_PASADO;
	float influencia = CONST_MIDICLORIANOS;
	float const_probabilidad = CONST_PROBABILIDAD;

	midiclorianos = recibir_midiclorianos();
	printf("\nMIDICLORIANOS: %f\n", midiclorianos);

	voluntad = recibir_voluntad();
	
	definir_voluntad(voluntad);

	pasado = recibir_pasado();
	
	definir_pasado(pasado);

	influencia = calculo_influencia(midiclorianos);
	printf("\nFUERZA: %f\n", influencia);

	const_probabilidad = calculo_sith(voluntad, influencia, pasado);
	printf("\nPROBABILIDAD DE CONVERTIRSE EN SITH: %f%\n", const_probabilidad);

	return 0;
}