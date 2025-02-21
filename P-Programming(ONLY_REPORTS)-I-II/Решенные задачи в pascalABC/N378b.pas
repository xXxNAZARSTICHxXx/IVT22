program N378b;
const k=8; //обозначение константы
type //создание собственной переменной массива
massive=array[1..k] of real;
matrica=array[1..k] of massive;
var
   x:massive;//описание массива
   y:matrica;//описание матрицы
   //описание файловой переменной
   
procedure handread(var x:massive); //ввод массива
var
i:integer;
begin
  writeln('Введите 8 чисел для заполнения массива: ');
  for i:=1 to k do
    readln(x[i]); //позиция элемента
end;
   
{Заполение матрицы по заданной схеме/первую строку матрицы}
procedure counter(x:massive; var y:matrica);
var
i,j:integer;
begin
   for j:=1 to k do y[1,j]:=1; //заполнение первой строки матрицы
   //заполнение остальных строк матрицы 
   For i:=2 to k do //перебор строк матрицы от 2 до k*
     for j:=1 to k do //возведение в степень каждого элемента строки
       y[I,j]:=y[I-1,j]*x[j];
end;

//выводится квадратная матрица
procedure vivodmatr(var y:matrica); //эта процедура выведит на экран матрицу
var
I,j,n:byte;
Begin
  n:=8;
  writeln('Ваша матрица: ');
  For i:=1 to n do begin //перебор строк матрицы
    For j:=1 to n do //вывод каждого элемента
      If j<n then write(y[I,j]:8:2)
		  else writeln(y[I,j]:8:2);
   Writeln(' ');
   end;
end;

//вывод в файл матрицы
procedure vivodvtext(var y:matrica);
var 
Way: string;
YourFile: text; 
i,j,n:byte;
begin
  n:=8;
  writeln('Напиши адрес для создания отчета:');
  Readln(way);
  Assign(YourFile, Way);
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile);
  writeln(YourFile,'Ваша матрица: ');
  For i:=1 to n do begin //перебор строк матрицы
    For j:=1 to n do //вывод каждого элемента
      If j<n then write(YourFile, y[I,j]:8:2)
		  else writeln(YourFile,y[I,j]:8:2);
      Writeln(' ');
  end;
  closefile(YourFile);
end;



begin
  
  handread(x);
  counter(x,y);
  vivodmatr(y);
  vivodvtext(Y);
end.
