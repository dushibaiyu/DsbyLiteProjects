package com.example.cms;
//������
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class HttpDownloader
{
	/**
	 * ����URL�����ļ���ǰ��������ļ����е��������ı��������ķ���ֵ�����ļ����е�����
	 * 1.����һ��URL����
	 * 2.ͨ��URL���󣬴���һ��HttpURLConnection����
	 * 3.�õ�InputStram
	 * 4.��InputStream���ж�ȡ����
	 */
	private URL url = null;

	public String downStr(String urlStr)//�����ַ����ķ���
	{
		/**
		 * String��StringBuffer���Ƕ����Դ洢�Ͳ����ַ���������������ַ����ַ������ݡ�
		 * String�����ַ����������ǲ��ɸ��ĵĳ�������StringBuffer���ַ������������Ķ����ǿ���������޸ĵġ� 
		 */
		StringBuffer sb = new StringBuffer();
		String line = null;
		BufferedReader buffer = null;//BufferedReader�����ڴӻ������ж�ȡ����

		try
		{
			/**
			 * ��Ϊֱ��ʹ��InputStream�����ã�����Ƕ����BufferedReader������Ƕ�ȡ�ַ����Ĺ̶���ʽ��
			 */
			
			url = new URL(urlStr);// ����һ��URL����		
			HttpURLConnection urlConn = (HttpURLConnection) url.openConnection();// ����һ��Http����
			buffer = new BufferedReader(new InputStreamReader(urlConn.getInputStream()));// ʹ��IO����ȡ����
			
			while ((line = buffer.readLine()) != null)
			{
				sb.append(line);
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				buffer.close();
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
		return sb.toString();
	}

	/**
	 *  -1�����������ļ����� 
	 *   0�����������ļ��ɹ� 
	 *   1�������ļ��Ѿ�����
	 */
	public int downFile(String urlStr, String path, String fileName)//�����ļ��ķ���
	{
		InputStream inputStream = null;
		try
		{
			FileUtils fileUtils = new FileUtils();

			if (fileUtils.isFileExist(path + fileName))
			{
				return 1;
			}
			else
			{
				inputStream = getInputStreamFromUrl(urlStr);
				File resultFile = fileUtils.write2SDFromInput(path, fileName,inputStream);
				if (resultFile == null)
				{
					return -1;
				}
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
			return -1;
		}
		finally
		{
			try
			{
				inputStream.close();
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
		return 0;
	}

	/**
	 * ����URL�õ�������
	 */
	public InputStream getInputStreamFromUrl(String urlStr)
			throws MalformedURLException, IOException
	{
		url = new URL(urlStr);// ����һ��URL����	
		HttpURLConnection urlConn = (HttpURLConnection) url.openConnection();// ����һ��Http����
		InputStream inputStream = urlConn.getInputStream();//�õ�������
		
		return inputStream;
	}

}


