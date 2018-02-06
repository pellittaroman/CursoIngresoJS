/*1.	Para el departamento de facturación:
A.	Ingresar tres precios de productos y mostrar la suma de los mismos.
B.	Ingresar tres precios de productos y mostrar el promedio de los mismos.
C.	ingresar tres precios de productos  y mostrar precio final (más IVA 21%).
*/
function Sumar () 
{
	var a;
	var b;
	var c;
	var resultado;
	a=document.getElementById('PrecioUno').value;
	b=document.getElementById('PrecioDos').value;
	c=document.getElementById('PrecioTres').value;
	resultado= a+b+c;
	
    alert(resultado);
}
function Promedio () 
{
	var a;
	var b;
	var c;
    var promedio;
	a=document.getElementById('PrecioUno').value;
	b=document.getElementById('PrecioDos').value;
	c=document.getElementById('PrecioTres').value;
	promedio =(a+b+c)/3;
	alert(promedio);

}

function PrecioFinal () 
{ 
	var a;
	var b;
	var c;
	var suma;
	var iva;
	var precio;
	a=document.getElementById('PrecioUno').value;
	b=document.getElementById('PrecioDos').value;
	c=document.getElementById('PrecioTres').value;
	suma= a+b+c;
	iva= suma*0.21;
	precio=suma + iva;
	alert(precio);

}