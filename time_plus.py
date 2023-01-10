def time_plus(filename, hour):

    from PIL import Image
    import piexif
    import datetime 

    img = Image.open(filename)
    exif_dict = piexif.load(img.info["exif"])

    t = exif_dict["0th"][306]
    t = t.decode()
    t = datetime.datetime.strptime(t, '%Y:%m:%d %H:%M:%S')
    t += datetime.timedelta(hours=hour)
    t = datetime.datetime.strftime(t, '%Y:%m:%d %H:%M:%S')
    t = t.encode()

    exif_dict["0th"][306] = t
    exif_dict["Exif"][36867] = t
    exif_dict["Exif"][36868] = t

    exif_bytes = piexif.dump(exif_dict)
    piexif.insert(exif_bytes, filename)

if __name__ == "__main__":
    time_plus('7654.JPG', 12)