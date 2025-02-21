program N136a; //название программы

const  //обозначение константы n
n = 10;

type //введение собственного типа massive
massive=array[1..n] of integer;

var
a:massive; //обозачаем массив своим типом
i,s,t:integer; //i-позиция в массиве; s-сумматор; t-нарастающее число (последовательность чисел(1,2,3,4...n);

Way: string; //way - путь файла для записи
YourFile: text; //YourFile - вывод в файл

begin
  writeln('Напиши адрес для создания отчета:');
  Readln(way); //считывание адреса для записи файла
  Assign(YourFile, Way); //объявление пути файла
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //проверка на файл

  
    t:=0; // "нарастать число будет в цикле"
  for i:=1 to n do begin 
    t:=t+1; // "наращивание числа"
    a[i]:=t; // "присвоение его в массив"
    s:=s+a[i]; // "суммирование присвоенных чисел"
    end;
  writeln(YourFile,'Сумма чисел массива равна: ',s); //вывод файла в отчет
  closefile(YourFile); //закритие файла
end. //конец программы
