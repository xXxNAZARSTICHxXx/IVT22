import 'package:flutter/material.dart';
import '../models/photo_model.dart';

class DetailScreen extends StatelessWidget {
  final Photo photo;

  DetailScreen({required this.photo});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Photo Details')),
      body: Column(
        children: [
          Image.network(photo.imgSrc),
          Text('Rover: ${photo.rover.name}'),
        ],
      ),
    );
  }
}