﻿program N223j; //название программы
const n=1000; //максимально допустимый массив - ограничивающая константа
type massive=array[1..n] of integer; //собственный тип massive
var
a:massive; // присвоение с использованием собственного типа
i,k,e,noth,v:integer; //i-цикл; k-позиция ПЕРВОГО отрицательного числа e-диапазон задействованного массива; 
//v-заполнялка массива; noth-переменная связанная с количеством нечетных
Logic,turn: boolean; //выключатель кода
Question: Char; //Ответ на "выключатель" 
Way: string; //way - путь файла для записи
YourFile: text; //YourFile - вывод в файл
begin
  //writeln('Напиши адрес для создания отчета:');
  //Readln(way); //считывание адреса для записи файла
  //Assign(YourFile, Way); //объявление пути файла
  //if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile); //проверка на файл
  //while logic = false do begin
  
  turn:=false;
  noth:=0;
  writeln('Введите количество символов массива, которые вы хотите использовать: ');
  readln(e); //диапазон задействованного массива //В ПРОЦЕДУРУ
  writeln('Заполните массив числами, вы выбрали ', e,' символов');
  
  for i:=1 to e do begin //цикл заполения задействованного диапазона массива
    readln(v);  //В ПРОЦЕДУРУ
    a[i]:=v;
  end;
  
  if a[1]<=0 then begin //проверка на то,что первое число НЕ <1
    writeln('Условие задачи 223ж не соблюдается... ОШИБКА');
    exit;
  end;
  
  i:=1;
  k:=0;
  while turn=false do begin //проверка на ПЕРВОЕ отрицательное число
    k:=k+1; //расчет позиции отрицательного числа
    i:=i+1; //продвижение i для создания
    if a[i]<0 then
      turn:=true;
  end;

  for i:=1 to k do //поиск удвоенных нечетных
    if (a[i] mod 2 = 0) then begin //удвоение превращаем в обычное, проверяя его
    a[i]:=a[i] div 2; //делаем обычное число
    if(a[i] mod 2 = 1) then //...если оно нечетное
      noth:=noth+1; //отметить его в переменной noth
  end;
  
  writeln('Количество удвоенных нечетных до первого отрицательного числа:', noth);
  
  //writeln(YourFile, 'Количество удвоенных нечетных: ',noth); //вывод отчета
  //Writeln('Хотите использовать программу еще раз? Y\N');
  //Readln(Question); //считывает ответ при Y-выключатель включен, при N-выключатель выключен
  //If question = 'N' then Logic:= True; //если выключатель выключен
  //end;
  //closefile(YourFile); //закрываем файл
end.