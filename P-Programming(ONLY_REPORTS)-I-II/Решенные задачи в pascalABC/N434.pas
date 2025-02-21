program N434;
const n=50;
type massive=array[1..n] of real; //создание собственной переменной
var
a,b:massive; //массивы (один массив для сокращения кода будет использоваться как глобальный параметр функции)
v,w,maxv:byte; //ограничители массива и позиции максимальных элементов в массивах
//(один ограничитель массива для сокращения кода будет использоваться как глобальный параметр функции)
Logic: boolean; //выключатель кода
Question: Char; //Ответ на "выключатель" 
Way: string; //way - путь файла для записи
YourFile: text; //YourFile - вывод в файл

//ограничитель массивов
procedure constant(var v:byte);
begin
  repeat
    write('Введите ограничитель для массива не больше, чем 50: ');
    readln(v);
  until (v<51);
end;

//ввод массивов случайным образом
procedure input(var a:massive; var v:byte);
var
i:byte;
begin
  randomize;
  for i:=1 to v do
    a[i]:=random(100)+(random(10)/10);
end;    

//поиск позиций максимальных элементов    
procedure maximum(var a:massive; var v:byte; var maxv:byte);
var
i:byte;
maximal:real;
begin
  maximal:=a[1];
  for i:=1 to v do begin
    if a[i]>maximal then begin
    maximal:=a[i];
    maxv:=i;
    end;
    end;
end;

//замена нужных элементов массива на 0.5
procedure complete(var a:massive; var v:byte; var maxv:byte);
var
i:byte;
begin
  for i:=maxv+1 to v do
    a[i]:=0.5;
end;

//вывод массивов и вывод массивов в файл
procedure output(var a:massive; var v:byte);
var
i:byte;
begin 
  for i:=1 to v do begin
    write(a[i]:5:1);
    write(YourFile,a[i]:5:1);
    end;
  writeln;
  writeln(YourFile);
end;

begin
  Logic:=false;
  writeln('Напиши адрес для создания отчета:');
  Read(way); //считывание адреса для записи файла
  Assign(YourFile, Way); //объявление пути файла
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //проверка на файл
  while logic = false do begin
    
    {Символ >, означает вывод в файл; Все writeln, означают дружественный интерфейс}
    
    writeln('Начальные массивы: ');
 {>}writeln(YourFile,'Начальные массивы: ');
    constant(v); //Вводим ограничитель для матрицы А
    writeln('Массив А: ');
    input(a,v); //Ввод случайным образом матрицы А
 {>}writeln(YourFile,'Массив А: ');
    output(a,v); //Вывод начальной матрицы А
    constant(w); //Вводим ограничитель для матрицы B
    input(b,w); //Ввод случайным образом матрицы B
    writeln('Массив B: ');
 {>}writeln(YourFile,'Массив B: ');
    output(b,w); //Вывод начальной матрицы B
    maximum(a,v,maxv); //Нахождение максимального элемента в матрице А
    complete(a,v,maxv); //Изменяем все значения после максимального элемента на 0.5 в матрице А
    maximum(b,w,maxv); //Нахождение максимального элемента в матрице B
    complete(b,w,maxv); //Изменяем все значения после максимального элемента на 0.5 в матрице В
    writeln;
 {>}writeln(YourFile);
    writeln('Конечные массивы: ');
    writeln('Массив А: ');
 {>}writeln(YourFile,'Конечные массивы: ');
 {>}writeln(YourFile,'Массив А: ');
    output(a,v); //Вывод конечной матрицы А
    writeln('Массив B: ');
 {>}writeln(YourFile,'Массив B: ');
    output(b,w); //Вывод конечной матрицы B
 {>}writeln(YourFile);
 {>}writeln(YourFile);
    
    Writeln('Хотите использовать программу еще раз? Y\N'); 
    Read(Question); //считывает ответ при Y-выключатель включен, при N-выключатель выключен
    if question = 'N' then Logic:= True; //если выключатель выключен
  end;
  closefile(YourFile); //закрываем файл
end.
