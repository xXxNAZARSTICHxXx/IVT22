import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('Лабораторная работа'),
        ),
        body: MyHomePage(),
      ),
    );
  }
}

class MyHomePage extends StatelessWidget {
  final List<String> imageUrls = [
    'https://images.steamusercontent.com/ugc/2289584579656747715/B186C40800D8E91221D2351401A15321455CA732/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true',
    'https://images.steamusercontent.com/ugc/2288456143558874093/15F50EC251CF208DE9FFDCAF39B4FFCC0870F56A/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true',
    'https://images.steamusercontent.com/ugc/2289584038852066896/532D024D691108AE98DC040B15AA175A90BF8F26/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true',
    'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ5DTHx00CTNRylQBQCxzrbo7wQqKPDG8qYVQ&s',
    'https://images.steamusercontent.com/ugc/2443837305411181220/1B0C3F261269AC829FD7B8A60A20E17CD5E93466/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true',
    'https://steamuserimages-a.akamaihd.net/ugc/2289584038860287315/EA1A15F9C89D5CEE310B58CFD2C4C65033BDBAF3/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true',
    'https://steamuserimages-a.akamaihd.net/ugc/2296340613030288972/E657E58B01D86BB8DD75FA5C892772D6C0B6DC93/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true',
    'https://art.pixilart.com/55149fb6d4bd657.png',
    'https://images.steamusercontent.com/ugc/2292958473549295139/0ECA452030B24F305E9CECBEDFD2F2BCEC698960/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true',
  ];

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: <Widget>[
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              buildImageContainer(imageUrls[0]),
              buildImageContainer(imageUrls[1]),
              buildImageContainer(imageUrls[2]),
            ],
          ),
          SizedBox(height: 10), 
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              buildImageContainer(imageUrls[3]),
              buildImageContainer(imageUrls[4]),
              buildImageContainer(imageUrls[5]),
            ],
          ),
          SizedBox(height: 10),
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              buildImageContainer(imageUrls[6]),
              buildImageContainer(imageUrls[7]),
              buildImageContainer(imageUrls[8]),
            ],
          ),
        ],
      ),
    );
  }


  Widget buildImageContainer(String imageUrl) {
    return Container(
      width: 100,
      height: 100,
      decoration: BoxDecoration(
        borderRadius: BorderRadius.circular(10),
        boxShadow: [BoxShadow(color: Colors.grey.withOpacity(0.5), blurRadius: 5)],
      ),
      child: ClipRRect(
        borderRadius: BorderRadius.circular(10),
        child: Image.network(imageUrl, fit: BoxFit.cover),
      ),
    );
  }
}
