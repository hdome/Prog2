import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.OutputStream;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import javax.imageio.ImageIO;

public class AsciiPrinter {

	private static final char[] ASCII_PIXELS = { '$', '#', '*', ':', '.', ' ' };
	private static final byte[] NEW_LINE = "\n".getBytes();

	private OutputStream outputStream;
	private BufferedImage image;

	public AsciiPrinter(OutputStream outputStream, BufferedImage image) {
		this.outputStream = outputStream;
		this.image = image;
	}

	public void print() throws IOException {
		for (int i = 0; i < image.getHeight(); i++) {
			for (int j = 0; j < image.getWidth(); j++) {
				outputStream.write(getAsciiChar(image.getRGB(j, i)));
			}
			outputStream.write(NEW_LINE);
		}
	}

	public static char getAsciiChar(int pixel) {
		return getAsciiCharFromGrayScale(getGreyScale(pixel));
	}

	public static int getGreyScale(int argb) {
		int red = (argb >> 16) & 0xff;
		int green = (argb >> 8) & 0xff;
		int blue = (argb) & 0xff;
		return (red + green + blue) / 3;
	}

	public static char getAsciiCharFromGrayScale(int greyScale) {
		return ASCII_PIXELS[greyScale / 51];
	}

}

public class Main {

	public static void main(String[] args) throws IOException {
		String imageName = args[0];
		String textFileName = args.length != 2 ? null : args[1];
		OutputStream outputStream = textFileName == null ? System.out : new FileOutputStream(textFileName);
		BufferedImage image = ImageIO.read(new File(imageName));

		new AsciiPrinter(outputStream, image).print();
	}

}