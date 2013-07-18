package com.example.cms;
//ftp�����࣬��δ����
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.RandomAccessFile;
import org.apache.commons.net.ftp.FTP;
import org.apache.commons.net.ftp.FTPClient;
import org.apache.commons.net.ftp.FTPFile;
import org.apache.commons.net.ftp.FTPReply;
import android.os.Environment;
public class FTPManager {
// �ϴ�����
private void ftpUpload() {
  new Thread() {
   public void run() {
    try {
     System.out.println("��������ftp������....");
     FTPManager ftpManager = new FTPManager();
     if (ftpManager.connect()) {
      if (ftpManager.uploadFile(ftpManager.rootPath + "UpdateXZMarketPlatform.apk", "mnt/sdcard/")) {
       ftpManager.closeFTP();
      }
     }
    } catch (Exception e) {
     // TODO: handle exception
     // System.out.println(e.getMessage());
    }
   }
  }.start();
}
// ��������
private void ftpDownload() {
  new Thread() {
   public void run() {
    try {
     System.out.println("��������ftp������....");
     FTPManager ftpManager = new FTPManager();
     if (ftpManager.connect()) {
      if (ftpManager.downloadFile(ftpManager.rootPath, "20120723_XFQ07_XZMarketPlatform.db")) {
       ftpManager.closeFTP();
      }
     }
    } catch (Exception e) {
     // TODO: handle exception
     // System.out.println(e.getMessage());
    }
   }
  }.start();
}
FTPClient ftpClient = null;
public String rootPath = Environment.getExternalStorageDirectory().getAbsolutePath() + "/";
public FTPManager() {
  ftpClient = new FTPClient();
}
// ���ӵ�ftp������
public synchronized boolean connect() throws Exception {
  boolean bool = false;
  if (ftpClient.isConnected()) {
   ftpClient.disconnect();
  }
  ftpClient.setDataTimeout(20000);
  ftpClient.setControlEncoding("utf-8");
 // ftpClient.connect("ip��ַ", �˿�);
  if (FTPReply.isPositiveCompletion(ftpClient.getReplyCode())) {
   if (ftpClient.login("�û���", "����")) {
    bool = true;
    System.out.println("ftp���ӳɹ�");
   }
  }
  return bool;
}
// �����ļ���
public boolean createDirectory(String path) throws Exception {
  boolean bool = false;
  String directory = path.substring(0, path.lastIndexOf("/") + 1);
  int start = 0;
  int end = 0;
  if (directory.startsWith("/")) {
   start = 1;
  }
  end = directory.indexOf("/", start);
  while (true) {
   String subDirectory = directory.substring(start, end);
   if (!ftpClient.changeWorkingDirectory(subDirectory)) {
    ftpClient.makeDirectory(subDirectory);
    ftpClient.changeWorkingDirectory(subDirectory);
    bool = true;
   }
   start = end + 1;
   end = directory.indexOf("/", start);
   if (end == -1) {
    break;
   }
  }
  return bool;
}
// ʵ���ϴ��ļ��Ĺ���
public synchronized boolean uploadFile(String localPath, String serverPath) throws Exception {
  // �ϴ��ļ�֮ǰ�����жϱ����ļ��Ƿ����
  File localFile = new File(localPath);
  if (!localFile.exists()) {
   System.out.println("�����ļ�������");
   return false;
  }
  System.out.println("�����ļ����ڣ�����Ϊ��" + localFile.getName());
  createDirectory(serverPath); // ����ļ��в����ڣ������ļ���
  System.out.println("�������ļ����·����" + serverPath + localFile.getName());
  String fileName = localFile.getName();
  // ��������ļ����ڣ��������ļ�Ҳ�ڣ��ϴ��ļ������������Ҳ�����˶ϵ��ϴ�
  long localSize = localFile.length(); // �����ļ��ĳ���
  FTPFile[] files = ftpClient.listFiles(fileName);
  long serverSize = 0;
  if (files.length == 0) {
   System.out.println("�������ļ�������");
   serverSize = 0;
  } else {
   serverSize = files[0].getSize(); // �������ļ��ĳ���
  }
  if (localSize <= serverSize) {
   if (ftpClient.deleteFile(fileName)) {
    System.out.println("�������ļ�����,ɾ���ļ�,��ʼ�����ϴ�");
    serverSize = 0;
   }
  }
  RandomAccessFile raf = new RandomAccessFile(localFile, "r");
  // ����
  long step = localSize / 100;
  long process = 0;
  long currentSize = 0;
  // ���ˣ���ʽ��ʼ�ϴ��ļ�
  ftpClient.enterLocalPassiveMode();
  ftpClient.setFileType(FTP.BINARY_FILE_TYPE);
  ftpClient.setRestartOffset(serverSize);
  raf.seek(serverSize);
  OutputStream output = ftpClient.appendFileStream(fileName);
  byte[] b = new byte[1024];
  int length = 0;
  while ((length = raf.read(b)) != -1) {
   output.write(b, 0, length);
   currentSize = currentSize + length;
   if (currentSize / step != process) {
    process = currentSize / step;
    if (process % 10 == 0) {
     System.out.println("�ϴ����ȣ�" + process);
    }
   }
  }
  output.flush();
  output.close();
  raf.close();
  if (ftpClient.completePendingCommand()) {
   System.out.println("�ļ��ϴ��ɹ�");
   return true;
  } else {
   System.out.println("�ļ��ϴ�ʧ��");
   return false;
  }
}
// ʵ�������ļ����ܣ���ʵ�ֶϵ�����
public synchronized boolean downloadFile(String localPath, String serverPath) throws Exception {
  // ���жϷ������ļ��Ƿ����
  FTPFile[] files = ftpClient.listFiles(serverPath);
  if (files.length == 0) {
   System.out.println("�������ļ�������");
   return false;
  }
  System.out.println("Զ���ļ�����,����Ϊ��" + files[0].getName());
  localPath = localPath + files[0].getName();
  // �����ж����ص��ļ��Ƿ��ܶϵ�����
  long serverSize = files[0].getSize(); // ��ȡԶ���ļ��ĳ���
  File localFile = new File(localPath);
  long localSize = 0;
  if (localFile.exists()) {
   localSize = localFile.length(); // ��������ļ����ڣ���ȡ�����ļ��ĳ���
   if (localSize >= serverSize) {
    System.out.println("�ļ��Ѿ���������");
    File file = new File(localPath);
    file.delete();
    System.out.println("�����ļ����ڣ�ɾ���ɹ�����ʼ��������");
    return false;
   }
  }
  // ����
  long step = serverSize / 100;
  long process = 0;
  long currentSize = 0;
  // ��ʼ׼�������ļ�
  ftpClient.enterLocalActiveMode();
  ftpClient.setFileType(FTP.BINARY_FILE_TYPE);
  OutputStream out = new FileOutputStream(localFile, true);
  ftpClient.setRestartOffset(localSize);
  InputStream input = ftpClient.retrieveFileStream(serverPath);
  byte[] b = new byte[1024];
  int length = 0;
  while ((length = input.read(b)) != -1) {
   out.write(b, 0, length);
   currentSize = currentSize + length;
   if (currentSize / step != process) {
    process = currentSize / step;
    if (process % 10 == 0) {
     System.out.println("���ؽ��ȣ�" + process);
    }
   }
  }
  out.flush();
  out.close();
  input.close();
  // �˷�������ȷ����������ϣ����û�д˷��������ܻ�����ֳ�������
  if (ftpClient.completePendingCommand()) {
   System.out.println("�ļ����سɹ�");
   return true;
  } else {
   System.out.println("�ļ�����ʧ��");
   return false;
  }
}
// ���ftp�ϴ��򿪣��͹رյ�
public void closeFTP() throws Exception {
  if (ftpClient.isConnected()) {
   ftpClient.disconnect();
  }
}
}
