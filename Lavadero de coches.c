// PROGRAMA  CREACION DE UN SOFTWARE PARA UN LAVADERO DE COCHES

#include<stdio.h>   
#include<stdlib.h> 
#include<string.h>
#include<conio.h>    
#include<time.h>  

// 1 NUEVO CLIENTE
typedef struct
{ 
	char nombre[50],apellido1[50],apellido2[50],bono,telefono[10];
	int nCliente[100];
	float valorCargado;
}ficha;
void nuevoCliente(); // Registra un nuevo cliente


// 2 CLIENTE EXISTENTE
typedef struct
{
	char nombre[50],apellido1[50],apellido2[50],bono, fecha[30], telefono;
	int nCliente;
	float saldo;
}modificarClientes;
void clienteExistente();  


// 3 LAVADO SENCILLO
typedef struct
{
	char fecha[15],hora[15], bono;
	int nLavados,codigo;

}lavado;
void lavadoSencillo(); // Realiza un lavado sencillo


// 4 ADMINISTRADOR
void administrador(); // Entrar como administrador
void cambioContrasena(); // Cambia la contraseña
void cambioRegistro(); // Edita un usuario
void actualizarRegistro(int n); // Borra o edita un registro



// ** MENU ** //
int main()
{
	int  opcion, salirBucle=0;
	char continuar;
	
	system ("color 0A"); // CAMBIA COLOR DEL FONDO
	
	do //Bucle para realizar otra operacion
	{
		printf("************** NUEVO SOFTWARE DEL LAVADERO DE COCHES **************\n\n");
		
		do //Bucle del menu   
		{
			printf("Elige una de las siguientes opciones:\n"); 
			printf("\t1 Nuevo cliente\n\t2 Cliente existente\n\t3 Lavado sencillo\n\t4 Entrar como administrador\n\t5 Salir del programa\n");
			scanf("%d", &opcion); fflush(stdin);
			if (opcion<1 || opcion>5)
				printf("Valor introducido incorrecto\n\n");
		}
		while(opcion<1 || opcion>5);
		printf("\n");

		switch(opcion)
		{	
		case 1: // Nuevo cliente
			{
				printf("Ha seleccionado registrar a un nuevo usuario\n");
				nuevoCliente();
				break;
			}			

		case 2: // Cliente existente
			{
				printf("Ha seleccionado cliente existente\n");
				clienteExistente();
				break;
			}
		
		case 3:  // Lavado sencillo
			{
				printf("Ha seleccionado lavado sencillo\n");
				lavadoSencillo();
				break;
			}
			
		case 4: // Administrador
			{
				printf("Ha seleccionado entrar como administrador\n");
				administrador();
				break;
			}
		case 5: // Salir del programa
			break;

		default: 
			printf("Valor incorrecto\n");

		}

		if(opcion==5)
		{
			continuar='n';
		}
		else
		{
			do
			{
				printf("\n\nDesea hacer otra operacion (s/n)?\n");
				scanf("%c",&continuar); fflush(stdin);
				if(continuar=='S' || continuar=='s' )
				{
					system("cls"); // BORRA LOS DATOS DE LA CONSOLA
					salirBucle=1;
				}
				else if(continuar=='N' || continuar=='n' )
					salirBucle=1;
				else
				{
					printf("Valor incorrecto\n");
					salirBucle=0;
				}
			}while(salirBucle==0);
		}
		salirBucle=0; 
		
	}while(continuar=='S'||continuar=='s');
	
	system("cls");
	
	printf("\n\t\tFIN DE PROGRAMA\n\n");
	system("pause");
}


// 1 FUNCION DE NUEVO CLIENTE
void nuevoCliente()	 
{
	ficha cliente[100];
	ficha contador[100];        
	int i=0,j=0;         
	char eleccion;
	int salirBucle=0; 
	int comprobacionBono=0,comprobacionTel=0;

	FILE* nCliente; 
	nCliente=fopen("APELLIDOS.txt","a");
	fclose(nCliente);

	nCliente=fopen("APELLIDOS.txt","r");

	if(nCliente==NULL)
	{
		printf("(Error al abrir el fichero)\n");
		return;
	}
	else 
		printf("(Fichero abierto)\n\n");

	while(fscanf(nCliente,"%d %s %s %s %s %s %f",&contador[j].nCliente, &contador[j].nombre, &contador[j].apellido1, &contador[j].apellido2, &contador[j].telefono,&contador[j].bono, &contador[j].valorCargado)!=EOF)
	{
		j++;
	}
	fclose(nCliente);	

	nCliente=fopen("APELLIDOS.txt","a");
	do			
	{
		printf("Cliente %d\n",j+1);
		fprintf(nCliente,"%d\t",j+1);
		

		printf("Nombre:");
		gets(cliente[i].nombre); fflush(stdin);
		fprintf(nCliente,"%s\t",cliente[i].nombre);
		
		printf("Primer apellido:");
		gets(cliente[i].apellido1); fflush(stdin);
		fprintf(nCliente,"%s\t",cliente[i].apellido1);

		printf("Segundo apellido:");
		gets(cliente[i].apellido2); fflush(stdin);
		fprintf(nCliente,"%s\t",cliente[i].apellido2);
		
		do
		{
			printf("Telefono:");
			scanf("%s",cliente[i].telefono); fflush(stdin);
			comprobacionTel=strlen(cliente[i].telefono);
			if(comprobacionTel!=9)
				printf("\nEl numero de telefono no contiene en numero necesario de caracteres, por favor introduzca de nuevo el numero\n\n");
		}while(comprobacionTel!=9);
		comprobacionTel=0; 
		fprintf(nCliente,"%s\t",cliente[i].telefono);

		do
		{
			printf("\nDispone de tres tipos de bonos\n\tBono A: valor de 100 euros\n\tBono B: valor de 70 euros\n\tBono C: valor de 30 euros\n");
			printf("Seleccione el bono que desea recargar: ");
			scanf("%c",&cliente[i].bono); fflush(stdin);
		
			if(cliente[i].bono=='A')
			{
				cliente[i].valorCargado=100;
				salirBucle=1;
			}
			else if (cliente[i].bono=='B')
			{
				cliente[i].valorCargado=70;
				salirBucle=1;
			}
			else if (cliente[i].bono=='C')
			{
				cliente[i].valorCargado=30;
				salirBucle=1;
			}
			else
				printf("\nValor introducido incorrecto\n\n");		
		}while(salirBucle==0);
		salirBucle=0;

		fprintf(nCliente,"%c\t",cliente[i].bono); 
		fprintf(nCliente,"%.2f\n",cliente[i].valorCargado); 
	
		do
		{
			printf("\nDesea annadir algun otro nuevo cliente (s/n)?\n");
			scanf("%c", &eleccion); fflush(stdin);
			if(eleccion=='s' || eleccion=='S' || eleccion=='n' || eleccion=='N' )
				salirBucle=1;
			else 
				printf("Valor incorrecto\n\n");
		}while(salirBucle==0);
		printf("\n\n");

		i++;
		j++;
			
	}while(eleccion=='s'||eleccion=='S');

	fclose(nCliente);					
}



// 2 FUNCION CLIENTE EXISTENTE
void clienteExistente()
{
	
	int i=0, j=0, tarjeta=0, salirBucle=0, num=0;
	char opcion; 
//	int comprobacionLavado=0; 
	modificarClientes actualizado[100];

	FILE *clienteActualizado;
	clienteActualizado=fopen("APELLIDOS.txt","a");
	fclose(clienteActualizado);   

	clienteActualizado=fopen("APELLIDOS.txt","r"); 
	
	if(clienteActualizado==NULL)
	{
		printf("(Error al abrir el fichero)\n");
		return;
	}
	else 
		printf("(Fichero abierto)\n\n");

	while(fscanf(clienteActualizado,"%d %s %s %s %s %s %f",&actualizado[j].nCliente, &actualizado[j].nombre, &actualizado[j].apellido1, &actualizado[j].apellido2, &actualizado[j].telefono, &actualizado[j].bono, &actualizado[j].saldo)!=EOF)
	{
		j++;
	}

	num=j;  // Guardo el numero de clientes registrados
	j=0;
	
	
	do
	{
		printf("Introduzca la tarjeta:");
		scanf("%d",&tarjeta); 
		fflush(stdin);
	
		for(i=0;i<num;i++)
		{
		j++;
			if(tarjeta==(i+1))
			{
				
				printf("\nBienvenido %s %s %s\n",actualizado[i].nombre, actualizado[i].apellido1, actualizado[i].apellido2);
				printf("Su saldo actual es de %.2f (euros)\n",actualizado[i].saldo);
				salirBucle=1;
				break;
			}			
		}
	}while(salirBucle==0);
	
	salirBucle=0;

	fclose(clienteActualizado);

	do
	{
		printf("\nPresione N para hacer lavado normal (5 euros) y E para lavado especial (7 euros):");		
		scanf("%c",&opcion); fflush(stdin);
		
		if(opcion=='E')		
		{		
			printf("\n\nHa seleccionado lavado especial\n");		
			actualizado[i].saldo=actualizado[i].saldo-7;			
			if (actualizado[i].saldo>=0)
				printf("\nSu saldo actual es de %.2f\nDa inicio a su lavado",actualizado[i].saldo);		
			else if(actualizado[i].saldo<=0)			
			{			
				printf("\nNo tiene saldo suficiente para este tipo de lavado\n");			
				actualizado[i].saldo=actualizado[i].saldo+7;		
			}	
			salirBucle=1; // Salgo del bucle
		}	

		else if(opcion=='N')		
		{			
			printf("Ha seleccionado lavado normal\n");			
			actualizado[i].saldo=actualizado[i].saldo-5;			
			if (actualizado[i].saldo>=0)			
				printf("Su saldo actual es de %.2f (euros)\nDa inicio a su lavado\n",actualizado[i].saldo);			
			else if(actualizado[i].saldo<=0)			
			{
				printf("No tiene saldo suficiente para este tipo de lavado\n");				
				actualizado[i].saldo=actualizado[i].saldo+5;				
			}						
			salirBucle=1; // Salgo del bucle
		}

		else
			printf("Opcion incorrecta\n\n");	
	}while(salirBucle==0);
	salirBucle=0;

	clienteActualizado=fopen("APELLIDOS.txt","w");	
	for(i=0;i<num;i++)
	{
		fprintf(clienteActualizado,"%d\t",i+1);
		fprintf(clienteActualizado,"%s\t",actualizado[i].nombre);
		fprintf(clienteActualizado,"%s\t",actualizado[i].apellido1);
		fprintf(clienteActualizado,"%s\t",actualizado[i].apellido2);
		fprintf(clienteActualizado,"%d\t",actualizado[i].telefono);
		fprintf(clienteActualizado,"%c\t",actualizado[i].bono);
		fprintf(clienteActualizado,"%.2f\n",actualizado[i].saldo);
	}
	
	fclose(clienteActualizado);	
}





//3 FUNCION DE LAVADO SENCILLO
// No recarga
void lavadoSencillo()
{
	
	int i=0, codigo, cod=0, numeroLavados, salirBucle=0;
	int comprobacionLavado=0; //////
	int hora = time(NULL);  
	lavado sencillo[100];

	FILE  *lavado;
	
	// FECHA Y HORA
	time_t  tiempo;
	struct  tm  *timelocal;
	char    out_time[128],  d[25]; 
	tiempo = time(0);
	timelocal = localtime(&tiempo);
	strftime(out_time, sizeof(out_time), "%d/%m/%y  %H:%M:%S", timelocal);
	lavado = fopen("BONOSSENCILLOS.txt", "a"); 
	fprintf(lavado, "%s\t", out_time);
	
	fclose(lavado);


	lavado=fopen("BONOSSENCILLOS.txt","r");
	if(lavado==NULL)
	{
		printf("(Error al abrir el fichero)\n");
		return;
	}
	else 
		printf("(Fichero abierto)\n\n");

	while(fscanf(lavado,"%s %s %d %c %d",&sencillo[i].fecha, &sencillo[i].hora, &sencillo[i].nLavados, &sencillo[i].bono, &sencillo[i].codigo)!=EOF)
	{
		i++;
	}
	fclose(lavado);
	

	lavado=fopen("BONOSSENCILLOS.txt","a");			
	fprintf(lavado,"%d\t",i); 

	printf("Dispone de dos tipos de lavados:\n\tNormal: 7 euros\n\tEspecial: 9 euros\n");
	do
	{
		printf("Pulse N para contratar bono normal y E para contratar bono especial:");
		scanf("%c",&sencillo[i].bono); fflush(stdin);
		if(sencillo[i].bono=='N' || sencillo[i].bono=='E')	
		{
			fprintf(lavado,"%c\t",sencillo[i].bono);
			salirBucle=1;
		}
		else
			printf("Valor incorrecto\n\n");
	}while(salirBucle==0);
	salirBucle=0;
	
	//Codigo aleatorio
	srand(hora); // SEMILLA DE rand()
	codigo = rand()%100;
	printf("Su codigo es %d\n",codigo);
	fprintf(lavado,"%d\n",codigo);
	
	do
	{
		printf("Introduzca codigo para iniciar lavado:");		
		scanf("%d",&cod); fflush(stdin);	
		if(codigo!=cod)
			printf("Codigo incorrecto\n\n");	
	}while(codigo!=cod);	
		
	printf("Codigo correcto, se inicia el lavado\n");
	
	fclose(lavado);	
}




// 4 FUNCION DE ADMINISTRADOR
void administrador()
{
	char contrasena1;
	char contrasena2;
	int modificar=0, i=0,j=0,n;

	FILE *pf;
	pf=fopen("PASSWORD.txt","a");
	fclose(pf);
	
	pf=fopen("PASSWORD.txt","r");
	if(pf==NULL)
	{
		printf("(Error al abrir el fichero)\n");
		return;
	}
	else 
		printf("(Fichero abierto)\n\n");

	while(fscanf(pf,"%c",&contrasena1)!=EOF)
	{
		j++;
	}
	fclose(pf);	

	do
	{
		printf("Introduzca contrase%ca:",164);
		scanf("%c",&contrasena2); fflush(stdin);

		if(contrasena2==contrasena1)
		{
			printf("\nHa entrado como administrador\n");		
			do
			{
				printf("\nPulse 1 para modificar datos\nPulse 2 para modificar contrase%ca\n\n",164);
				scanf("%d",&modificar); fflush(stdin);
				if(modificar<1 || modificar>2)
				printf("El valor introducido es incorrecto\n\n");
			}while(modificar<1 || modificar>2);
	
		}
		else if(contrasena1!=contrasena2)
			printf("\nLo sentimos la contrase%ca  es incorrecta, vuelva a intentarlo.\n\n",164);
	}while(contrasena1!=contrasena2);
	
	switch(modificar)
	{
	case 1: // Modifica registro
		{
			cambioRegistro();
			break;
		}
		
	case 2: // Cambio contraseña
		{
			cambioContrasena();
			break;
		}
	default: 
		printf("Valor incorrecto\n");
	}		
}



// 4.1 FUNCION PARA MODIFICAR REGISTRO (ADMINISTRADOR)
void cambioRegistro()
{
	int i=0, j=0, k=0, n, tarjeta, salirBucle=0, opcion;
	char eliminar;

	modificarClientes administrador[100];

	FILE *admin;
	admin=fopen("APELLIDOS.txt","a");			
	fclose(admin); 
			
	admin=fopen("APELLIDOS.txt","r");
	if(admin==NULL)
	{
		printf("(Error al abrir el fichero)\n");
		return;
	}
	else 
		printf("(Fichero abierto)\n\n");
	
	while(fscanf(admin,"%d %s %s %s %d %s %f",&administrador[i].nCliente, &administrador[i].nombre, &administrador[i].apellido1, &administrador[i].apellido2, &administrador[i].telefono, &administrador[i].bono, &administrador[i].saldo)!=EOF)
	{
		i++;	
	}	
	n=i;  // Guardo el numero de clientes registrados
	fclose(admin);

	do
	{
		printf("Introduzca codigo del cliente a eliminar:");
		scanf("%d",&tarjeta); fflush(stdin);
		
		for(i=0;i<n;i++)
		{
			if(tarjeta==(i+1))
			{
				k=i;
				salirBucle=1;
				break;	
				
				
			}
			
		}
		if(salirBucle==0)
			printf("No existe el usuario\n\nIntroduzca de nuevo el codigo\n");
	}while(salirBucle==0);
	
	printf("\nEl usuario es %s %s %s\n",administrador[i].nombre, administrador[i].apellido1, administrador[i].apellido2);
		
	salirBucle=0;
	do
	{
		printf("Desea eliminarlo (s/n?):"); scanf("%c",&eliminar);fflush(stdin);
		if(eliminar=='S' ||eliminar=='s' ||eliminar=='N' ||eliminar=='n')
			salirBucle=1;
		else
			printf("Opcion incorrecta\n\n");
		
	}while(salirBucle==0);
	salirBucle=0;

	if(eliminar=='S' ||eliminar=='s')
	{
		admin=fopen("APELLIDOS.txt","w");
		for(i=0;i<n;i++)
		{
			if(i<k)
			{
				fprintf(admin,"%d\t",i+1);
				fprintf(admin,"%s\t",administrador[i].nombre);
				fprintf(admin,"%s\t",administrador[i].apellido1);
				fprintf(admin,"%s\t",administrador[i].apellido2);
				fprintf(admin,"%d\t",administrador[i].telefono);
				fprintf(admin,"%c\t",administrador[i].bono);
				fprintf(admin,"%.2f\n",administrador[i].saldo);
			}
			else if(i==k)
				printf("Registro eliminado\n");
			else if(i>k)
			{

				fprintf(admin,"%d\t",i);
				fprintf(admin,"%s\t",administrador[i].nombre);
				fprintf(admin,"%s\t",administrador[i].apellido1);
				fprintf(admin,"%s\t",administrador[i].apellido2);
				fprintf(admin,"%d\t",administrador[i].telefono);
				fprintf(admin,"%c\t",administrador[i].bono);
				fprintf(admin,"%.2f\n",administrador[i].saldo);
			}
		}
		fclose(admin);
	}
	else 
		printf("Usuario no modificado\n\n");
}



// 4.2 FUNCION PARA CAMBIAR CONTRASEÑA (ADMINISTRADOR)
void cambioContrasena()
{
	char contrasena1,contrasena2;

	FILE *pf;

	printf("Introduzca nueva contrase%ca:",164);
	scanf("%c",&contrasena1); fflush(stdin);
	printf("Confirme nueva contrase%ca:",164);
	scanf("%c",&contrasena2); fflush(stdin);
	if(contrasena1==contrasena2)
	{
		pf=fopen("PASSWORD.txt","w");
		fprintf(pf,"%c",contrasena1);
		fclose(pf);
		printf("Contrase%ca modificada\n",164);			
	}
	else
		printf("La contrase%cas introducidas son diferentes\n",164);

}
