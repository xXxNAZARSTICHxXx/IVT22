import 'dart:convert';
import 'package:http/http.dart' as http;
import '../models/photo_model.dart';

Future<List<Photo>> fetchRoverPhotos() async {
  final url = Uri.parse(
      'https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos?sol=1000&api_key=eQnprvXukgfNomTanZiHT1DqLApcABzFjI350dyZ');
  final response = await http.get(url);

  if (response.statusCode == 200) {
    final data = json.decode(response.body);
    final photosData = data['photos'] as List;
    return photosData.map((json) => Photo.fromJson(json)).toList();
  } else {
    throw Exception('Failed to load photos');
  }
}