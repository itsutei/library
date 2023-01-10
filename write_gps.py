def write_gps(filename, lat, lon):
    
    from PIL import Image
    import piexif

    img = Image.open(filename)
    exif_dict = piexif.load(img.info["exif"])

    lat *= 3600
    a = int(lat / 3600)
    lat -= a * 3600
    b = int(lat / 60)
    lat -= b * 60
    exif_dict["GPS"][2] = ((a, 1), (b, 1), (int(lat*100), 100) )

    lon *= 3600
    a = int(lon / 3600)
    lon -= a * 3600
    b = int(lon / 60)
    lon -= b * 60
    exif_dict["GPS"][4] = ((a, 1), (b, 1), (int(lon*100), 100) )

    exif_bytes = piexif.dump(exif_dict)
    piexif.insert(exif_bytes, filename)

if __name__ == "__main__":
    write_gps('7654.JPG', 35.331324, 139.620892)