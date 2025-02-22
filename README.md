```markdown
# Beta - เครื่องมือสำหรับการโจมตีเครือข่ายเวอร์ชั่นทดลอง

เครื่องมือนี้ถูกออกแบบมาเพื่อใช้ในการทดสอบเครือข่ายโดยการส่งแพ็กเก็ตข้อมูลไปยังเป้าหมายที่กำหนด ทำมาเพื่อการศึกษาเท่านั้น

## วิธีการติดตั้งทำตามขั้นตอนด้านล่าง

```


## ให้สิทธิ์การ execute ไฟล์ (สำคัญ)

```bash
chmod +x Beta-3M
```

## วิธีการใช้งาน

```bash
sudo ./Beta-3M <IP> <PORT> <THREADS> <METHOD>
```

### ตัวอย่างการใช้งาน

```bash
sudo ./Beta-3M 127.0.0.1 10015 10 UDP
```

### คำเตือน

- **threads**: ไม่แนะนำให้ตั้งค่าสูงเกินไปหากคุณใช้คลาวด์หรือพีซีที่ประสิทธิภาพไม่สูง แนะนำให้ตั้งค่าไม่เกิน 10

## คำถามที่พบบ่อย

### A: จะหา IP ของเซิร์ฟเวอร์เกมได้จากที่ไหน?
คุณสามารถหา IP ของเซิร์ฟเวอร์เกมได้จากข้อมูลที่ให้โดยผู้ให้บริการเกม หรือใช้เครื่องมือวิเคราะห์เครือข่ายเพื่อค้นหา

### A: จะดัก IP ได้อย่างไร?
คุณสามารถใช้แอพพลิเคชันเช่น **pcapdroid** บน Android เพื่อดักและวิเคราะห์แพ็กเก็ตข้อมูลบนเครือข่ายของคุณ โดยทั่วไปเกมส่วนใหญ่มักใช้ UDP

---

**หมายเหตุ**: เราจะไม่รับผิดชอบอะไรทั้งสิ้นถ้าเกิดความเสียหาย
```
