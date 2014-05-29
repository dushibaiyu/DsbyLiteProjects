package com.example.cms;
//д���ļ�������������
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;



public class FileUtils
{
	private String SDPATH;

	public String getSDPATH()
	{
		return SDPATH;
	}

	public FileUtils()
	{
		//�õ���ǰSDCARD�洢�豸��Ŀ¼ /SDCARD, Environment.getExternalStorageDirectory()��������Ƚ�ͨ��
		//SDPATH = Environment.getExternalStorageDirectory() + "/";
		SDPATH = cms.fileurl;
	}

	/**
	 * ��SD���ϴ����ļ�
	 */
	public File creatSDFile(String fileName) throws IOException
	{
		File file = new File(SDPATH + fileName);
		file.createNewFile();
		return file;
	}

	/**
	 * ��SD���ϴ���Ŀ¼
	 */
	public File creatSDDir(String dirName)
	{
		File dir = new File(SDPATH + dirName);
		dir.mkdir();
		return dir;
	}

	/**
	 * �ж�SD���ϵ��ļ����Ƿ����
	 */
	public boolean isFileExist(String fileName)
	{
		File file = new File(SDPATH + fileName);
		return file.exists();
	}

	/**
	 * ��һ��InputStream���������д�뵽SD����
	 */
	public File write2SDFromInput(String path, String fileName,
			InputStream input)
	{
		File file = null;
		OutputStream output = null;
		try//InputStream���������д�뵽SD���еĹ̶�����
		{
			creatSDDir(path);
			file = creatSDFile(path + fileName);
			output = new FileOutputStream(file);
			byte buffer[] = new byte[4 * 1024];
			while ((input.read(buffer)) != -1)
			{
				output.write(buffer);
			}
			output.flush();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		finally
		{
			try
			{
				output.close();
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		}
		return file;
	}
}