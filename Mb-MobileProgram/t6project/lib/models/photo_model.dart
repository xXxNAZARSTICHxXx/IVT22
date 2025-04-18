import 'rover_model.dart';

class Photo {
  final int id;
  final String imgSrc;
  final Rover rover;

  Photo({
    required this.id,
    required this.imgSrc,
    required this.rover,
  });

  factory Photo.fromJson(Map<String, dynamic> json) {
    return Photo(
      id: json['id'],
      imgSrc: json['img_src'],
      rover: Rover.fromJson(json['rover']),
    );
  }
}